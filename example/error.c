
#include "error.h"
#include "header.h"
#include "flags.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static char *
vsprintf_alloc(const char *format, va_list args)
{
	va_list args_copy;
	char *buf;
	size_t bufsize;
	int rc;

	bufsize = 32;

	while (bufsize <= 1024 * 1024) {
		buf = malloc(bufsize);
		if (buf == NULL) {
			return NULL;
		}

		va_copy(args_copy, args);
		rc = vsnprintf(buf, bufsize, format, args_copy);
		va_end(args_copy);

		if (rc >= 0 && (size_t)rc < bufsize) {
			return buf;
		}

		free(buf);
		bufsize *= 2;
	}

	return NULL;
}

ff lambda_error_eval_now(ff me, ff x) {
	if (me->custom) {
		fprintf(stderr, "%s", (char*)me->custom);
	} else {
		fprintf(stderr, "%s", "This is crazy!");
	}
	return x;
}

#ifdef DO_CACHING
int lambda_error_cache(ff me_abs, mapkey_t * ret, recursion_set * set) {
	return true;
}
#endif

ff lambda_error(const char *fmt, ...) {
	va_list args;

	va_start(args, fmt);
	char * str = vsprintf_alloc(fmt, args);
	va_end(args);

	struct fun ret = {
		.parent = 0,
		.x = 0,
		.leafs = 0,
		.eval_now = lambda_error_eval_now,
		.custom = str,

#ifdef DO_CACHING
		.cache = lambda_error_cache,
		.leafs_count = 0,
		.customsize = 0,
#endif
	};

	ff allocated = ALLOC(struct fun);
	*allocated = ret;

	return allocated;
}
