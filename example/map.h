
#pragma once

struct node;
struct map;
struct list;

struct map * map_alloc(const int size);
int map_add(struct map * m, struct list * l);

