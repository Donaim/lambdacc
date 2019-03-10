
#pragma once

#include <stdexcept>

template <typename T>
class svector {
protected:
	T * buffer;
	size_t size;
	size_t allocated;

public:
	svector(size_t initial_size)
	{
		this->allocated = initial_size;
		this->size = 0;
		this->buffer = (T*)malloc(sizeof(T) * initial_size);
	}

	inline size_t get_size() const { return this->size; }
	inline bool is_empty() const { return this->size == 0; }

	inline T operator [] (size_t i) const { return this->buffer[i]; }
	inline T at(size_t i) const {
		if (i < this->size) {
			return this->buffer[i];
		} else {
			throw std::runtime_error("index was outside of svector");
		}
	}
	inline T * atptr(size_t i) const {
		if (i < this->size) {
			return this->buffer + i;
		} else {
			throw std::runtime_error("index was outside of svector");
		}
	}

	// Return pointer to next free cell. Unsafe
	inline T * get_next(void)
	{
		return this->buffer + this->size++;
	}

	// No destructor, need to manual free
	void freeall(void) {
		free(this->buffer);
	}
};

