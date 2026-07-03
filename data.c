#include <stdio.h>
#include "util.h"

Book Library[library_storage] = {
    {1000, "Attack on Titan", "Hajime Isayama", BORROWED, 0},
    {1001, "Jujutsu Kaisen", "Gege Akutami", AVAILABLE, 0},
    {1002, "Mushoku Tensei", "Rifujin na Magonote", AVAILABLE, 0},
    {1003, "Demon Slayer", "Koyoharu Gotouge", AVAILABLE, 0},
    {1004, "One Piece", "Eiichiro Oda", BORROWED, 0},
    {1005, "My Hero Academia", "Kohei Horikoshi", BORROWED, 0},
    {1006, "Naruto", "Masashi Kishimoto", AVAILABLE, 0},
    {1007, "Death Note", "Tsugumi Ohba", AVAILABLE, 0},
};