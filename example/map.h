
#pragma once

struct node;
struct map;
struct list;
struct fun;

struct map * map_alloc(const int size);
int map_add(struct map * m, struct list * key, struct fun * value);

struct fun * map_get(struct map * m, struct list * key);

