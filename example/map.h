
#pragma once

struct node;
struct map;
struct list;

struct map * map_alloc(void);
int map_add(struct map * m, struct list * l);

