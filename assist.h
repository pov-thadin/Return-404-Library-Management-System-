#ifndef ASSIST_H
#define ASSIST_H

int extract_int(char *input);
int search_by_code(int code);
int search_by_str(char *str);
int get_book_index(int id);
void arrange_data(int from_index);
int generate_id();
#endif