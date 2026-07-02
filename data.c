#include <stdio.h>
#include "util.h"

Book Library[library_storage] = {
    {1000, "Attack on Titan", "Hajime Isayama", BORROWED},
    {1001, "Jujutsu Kaisen", "Gege Akutami", AVAILABLE},
    {1002, "Mushoku Tensei", "Rifujin na Magonote", AVAILABLE},
    {1003, "Demon Slayer", "Koyoharu Gotouge", AVAILABLE},
    {1004, "One Piece", "Eiichiro Oda", BORROWED},
    {1005, "My Hero Academia", "Kohei Horikoshi", BORROWED},
    {1006, "Naruto", "Masashi Kishimoto", AVAILABLE},
    {1007, "Death Note", "Tsugumi Ohba", AVAILABLE},
};