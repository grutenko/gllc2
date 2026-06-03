#include "litecad.h"

#include <assert.h>
#include <string.h>

#define TEST_COLORI(L, prop, name, idx, rgb)                                                                           \
        do                                                                                                             \
        {                                                                                                              \
                assert(lcPropPutStr((L), (prop), (name)) == 1);                                                        \
                char *str = lcPropGetStr((L), (prop));                                                                 \
                assert(str != NULL);                                                                                   \
                assert(strcmp(str, (name)) == 0);                                                                      \
                assert(lcPropGetInt((L), (prop##I)) == (idx));                                                         \
                assert(lcPropGetBool((L), (prop##I)) == 1);                                                            \
                assert(lcPropGetBool((L), (prop##T)) == 0);                                                            \
                assert(lcPropGetInt(L, (prop##T)) == (rgb));                                                           \
                                                                                                                       \
                assert(lcPropPutInt((L), (prop##I), (idx)) == 1);                                                      \
                str = lcPropGetStr((L), (prop));                                                                       \
                assert(str != NULL);                                                                                   \
                assert(strcmp(str, (name)) == 0);                                                                      \
                assert(lcPropGetInt((L), (prop##I)) == (idx));                                                         \
                assert(lcPropGetBool((L), (prop##I)) == 1);                                                            \
                assert(lcPropGetBool((L), (prop##T)) == 0);                                                            \
                assert(lcPropGetInt(L, (prop##T)) == (rgb));                                                           \
                                                                                                                       \
                assert(lcPropPutInt((L), (prop##T), (rgb)) == 1);                                                      \
                str = lcPropGetStr((L), (prop));                                                                       \
                assert(str != NULL);                                                                                   \
                assert(strcmp(str, (name)) == 0);                                                                      \
                assert(lcPropGetInt((L), (prop##I)) == (idx));                                                         \
                assert(lcPropGetBool((L), (prop##I)) == 1);                                                            \
                assert(lcPropGetBool((L), (prop##T)) == 0);                                                            \
                assert(lcPropGetInt(L, (prop##T)) == (rgb));                                                           \
        } while (0)

#define TEST_COLORT(L, prop, rgbstr, rgb)                                                                              \
        do                                                                                                             \
        {                                                                                                              \
                assert(lcPropPutStr((L), (prop), (rgbstr)) == 1);                                                      \
                char *str = lcPropGetStr((L), (prop));                                                                 \
                assert(str != NULL);                                                                                   \
                assert(strcmp(str, (rgbstr)) == 0);                                                                    \
                assert(lcPropGetBool((L), (prop##I)) == 0);                                                            \
                assert(lcPropGetBool((L), (prop##T)) == 1);                                                            \
                assert(lcPropGetInt(L, (prop##T)) == (rgb));                                                           \
        } while (0)

int main()
{
        void *drawing = lcCreateDrawing();
        assert(drawing);
        void *hblock = lcPropGetHandle(drawing, LC_PROP_DRW_BLOCK_MODEL);
        assert(hblock);
        void *L = lcDrwAddLayer(drawing, "LAYER", "Black", NULL, 1);
        assert(L);

        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Black", 0, 0x000000);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "90% Black", 1, 0x191919);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "80% Black", 2, 0x333333);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "70% Black", 3, 0x4D4D4D);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "60% Black", 4, 0x666666);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "50% Black", 5, 0x808080);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "40% Black", 6, 0x999999);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "30% Black", 7, 0xB3B3B3);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "20% Black", 8, 0xCCCCCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "10% Black", 9, 0xE6E6E6);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "White", 10, 0xFFFFFF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Blue", 11, 0x0000FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Cyan", 12, 0x00FFFF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Green", 13, 0x00FF00);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Yellow", 14, 0xFFFF00);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Red", 15, 0xFF0000);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Magenta", 16, 0xFF00FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Purple", 17, 0x9900CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Orange", 18, 0xFF6600);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Pink", 19, 0xFF99CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dark Brown", 20, 0x663333);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Powder Blue", 21, 0xCCCCFF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Pastel Blue", 22, 0x9999FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Baby Blue", 23, 0x6699FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Electric Blue", 24, 0x6666FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Twilight Blue", 25, 0x6666CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Navy Blue", 26, 0x003399);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Navy Blue", 27, 0x000066);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Desert Blue", 28, 0x336699);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dodger Blue", 29, 0x1389FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Sky Blue", 30, 0x00CCFF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Ice Blue", 31, 0x99FFFF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Smalt Blue", 32, 0x0068D0);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light BlueGreen", 33, 0x99CCCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Ocean Green", 34, 0x669999);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Moss Green", 35, 0x336666);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dark Green", 36, 0x003333);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Forest Green", 37, 0x006633);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Grass Green", 38, 0x009933);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Wild Willow", 39, 0xB5CC61);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Kentucky Green", 40, 0x339966);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light Green", 41, 0x33CC66);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Spring Green", 42, 0x33CC33);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Turquoise", 43, 0x66FFCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Sea Green", 44, 0x33CC99);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Faded Green", 45, 0x99CC99);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Ghost Green", 46, 0xCCFFCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Mint Green", 47, 0x99FF99);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Army Green", 48, 0x669966);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Avocado Green", 49, 0x669933);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Martian Green", 50, 0x99CC33);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dull Green", 51, 0x99CC66);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Chartreuse", 52, 0x99FF00);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Moon Green", 53, 0xCCFF66);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Murky Green", 54, 0x333300);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Olive Drab", 55, 0x666633);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Khaki", 56, 0x999966);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Olive", 57, 0x999933);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Banana Yellow", 58, 0xCCCC33);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light Yellow", 59, 0xFFFF66);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Chalk", 60, 0xFFFF99);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Pale Yellow", 61, 0xFFFFCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Brown", 62, 0x996633);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Red Brown", 63, 0xCC6633);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Gold", 64, 0xCC9933);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Autumn Orange", 65, 0xFF6633);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light Orange", 66, 0xFF9933);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Peach", 67, 0xFF9966);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Yellow", 68, 0xFFCC00);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Sand", 69, 0xFFCC99);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Walnut", 70, 0x663300);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Ruby Red", 71, 0x990000);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Brick Red", 72, 0xCC3300);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Tropical Pink", 73, 0xFF6666);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Soft Pink", 74, 0xFF9999);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Faded Pink", 75, 0xFFCCCC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dark Red", 76, 0x800000);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Crimson", 77, 0x993366);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Regal Red", 78, 0xCC3366);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Rose", 79, 0xCC3399);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Neon Red", 80, 0xFF0066);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Pink", 81, 0xFF6699);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Hot Pink", 82, 0xFF3399);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dusty Rose", 83, 0xCC6699);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Plum", 84, 0x660066);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Violet", 85, 0x990099);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light Violet", 86, 0xFF99FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Violet", 87, 0xCC66CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dusty Plum", 88, 0x996699);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Pale Purple", 89, 0xCC99CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Majestic Purple", 90, 0x9933CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Neon Purple", 91, 0xCC33FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Light Purple", 92, 0xCC66FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Twilight Violet", 93, 0x9966CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Easter Purple", 94, 0xCC99FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Purple", 95, 0x330066);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Grape", 96, 0x663399);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Blue Violet", 97, 0x9966FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Blue Purple", 98, 0x9900FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep River", 99, 0x6600CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Azure", 100, 0x6633FF);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Storm Blue", 101, 0x330099);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Deep Blue", 102, 0x3300CC);
        TEST_COLORI(L, LC_PROP_LAYER_COLOR, "Dark Blue", 103, 0x000080);
        TEST_COLORT(L, LC_PROP_LAYER_COLOR, "15,10,44", 0x0F0A2C);

        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Black", 0, 0x000000);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "90% Black", 1, 0x191919);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "80% Black", 2, 0x333333);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "70% Black", 3, 0x4D4D4D);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "60% Black", 4, 0x666666);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "50% Black", 5, 0x808080);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "40% Black", 6, 0x999999);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "30% Black", 7, 0xB3B3B3);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "20% Black", 8, 0xCCCCCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "10% Black", 9, 0xE6E6E6);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "White", 10, 0xFFFFFF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Blue", 11, 0x0000FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Cyan", 12, 0x00FFFF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Green", 13, 0x00FF00);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Yellow", 14, 0xFFFF00);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Red", 15, 0xFF0000);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Magenta", 16, 0xFF00FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Purple", 17, 0x9900CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Orange", 18, 0xFF6600);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Pink", 19, 0xFF99CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dark Brown", 20, 0x663333);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Powder Blue", 21, 0xCCCCFF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Pastel Blue", 22, 0x9999FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Baby Blue", 23, 0x6699FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Electric Blue", 24, 0x6666FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Twilight Blue", 25, 0x6666CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Navy Blue", 26, 0x003399);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Navy Blue", 27, 0x000066);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Desert Blue", 28, 0x336699);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dodger Blue", 29, 0x1389FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Sky Blue", 30, 0x00CCFF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Ice Blue", 31, 0x99FFFF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Smalt Blue", 32, 0x0068D0);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light BlueGreen", 33, 0x99CCCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Ocean Green", 34, 0x669999);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Moss Green", 35, 0x336666);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dark Green", 36, 0x003333);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Forest Green", 37, 0x006633);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Grass Green", 38, 0x009933);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Wild Willow", 39, 0xB5CC61);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Kentucky Green", 40, 0x339966);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light Green", 41, 0x33CC66);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Spring Green", 42, 0x33CC33);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Turquoise", 43, 0x66FFCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Sea Green", 44, 0x33CC99);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Faded Green", 45, 0x99CC99);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Ghost Green", 46, 0xCCFFCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Mint Green", 47, 0x99FF99);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Army Green", 48, 0x669966);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Avocado Green", 49, 0x669933);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Martian Green", 50, 0x99CC33);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dull Green", 51, 0x99CC66);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Chartreuse", 52, 0x99FF00);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Moon Green", 53, 0xCCFF66);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Murky Green", 54, 0x333300);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Olive Drab", 55, 0x666633);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Khaki", 56, 0x999966);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Olive", 57, 0x999933);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Banana Yellow", 58, 0xCCCC33);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light Yellow", 59, 0xFFFF66);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Chalk", 60, 0xFFFF99);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Pale Yellow", 61, 0xFFFFCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Brown", 62, 0x996633);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Red Brown", 63, 0xCC6633);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Gold", 64, 0xCC9933);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Autumn Orange", 65, 0xFF6633);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light Orange", 66, 0xFF9933);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Peach", 67, 0xFF9966);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Yellow", 68, 0xFFCC00);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Sand", 69, 0xFFCC99);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Walnut", 70, 0x663300);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Ruby Red", 71, 0x990000);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Brick Red", 72, 0xCC3300);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Tropical Pink", 73, 0xFF6666);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Soft Pink", 74, 0xFF9999);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Faded Pink", 75, 0xFFCCCC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dark Red", 76, 0x800000);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Crimson", 77, 0x993366);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Regal Red", 78, 0xCC3366);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Rose", 79, 0xCC3399);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Neon Red", 80, 0xFF0066);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Pink", 81, 0xFF6699);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Hot Pink", 82, 0xFF3399);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dusty Rose", 83, 0xCC6699);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Plum", 84, 0x660066);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Violet", 85, 0x990099);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light Violet", 86, 0xFF99FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Violet", 87, 0xCC66CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dusty Plum", 88, 0x996699);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Pale Purple", 89, 0xCC99CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Majestic Purple", 90, 0x9933CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Neon Purple", 91, 0xCC33FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Light Purple", 92, 0xCC66FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Twilight Violet", 93, 0x9966CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Easter Purple", 94, 0xCC99FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Purple", 95, 0x330066);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Grape", 96, 0x663399);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Blue Violet", 97, 0x9966FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Blue Purple", 98, 0x9900FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep River", 99, 0x6600CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Azure", 100, 0x6633FF);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Storm Blue", 101, 0x330099);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Deep Blue", 102, 0x3300CC);
        TEST_COLORI(L, LC_PROP_LAYER_FCOLOR, "Dark Blue", 103, 0x000080);
        TEST_COLORT(L, LC_PROP_LAYER_FCOLOR, "15,10,44", 0x0F0A2C);

        void *hpl = lcBlockAddPolyline(hblock, 0, 0, 0);
        lcPropPutHandle(hpl, LC_PROP_ENT_LAYER, L);
        // По умолчанию entity создается с COLORBYLAYER, FCOLORBYLAYER
        // Установка цвета через String меняет это
        assert(lcPropGetBool(hpl, LC_PROP_ENT_COLORBYLAYER) == 1);
        assert(lcPropGetBool(hpl, LC_PROP_ENT_FCOLORBYLAYER) == 1);

        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Black", 0, 0x000000);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "90% Black", 1, 0x191919);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "80% Black", 2, 0x333333);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "70% Black", 3, 0x4D4D4D);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "60% Black", 4, 0x666666);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "50% Black", 5, 0x808080);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "40% Black", 6, 0x999999);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "30% Black", 7, 0xB3B3B3);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "20% Black", 8, 0xCCCCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "10% Black", 9, 0xE6E6E6);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "White", 10, 0xFFFFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Blue", 11, 0x0000FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Cyan", 12, 0x00FFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Green", 13, 0x00FF00);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Yellow", 14, 0xFFFF00);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Red", 15, 0xFF0000);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Magenta", 16, 0xFF00FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Purple", 17, 0x9900CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Orange", 18, 0xFF6600);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Pink", 19, 0xFF99CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dark Brown", 20, 0x663333);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Powder Blue", 21, 0xCCCCFF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Pastel Blue", 22, 0x9999FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Baby Blue", 23, 0x6699FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Electric Blue", 24, 0x6666FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Twilight Blue", 25, 0x6666CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Navy Blue", 26, 0x003399);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Navy Blue", 27, 0x000066);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Desert Blue", 28, 0x336699);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dodger Blue", 29, 0x1389FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Sky Blue", 30, 0x00CCFF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Ice Blue", 31, 0x99FFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Smalt Blue", 32, 0x0068D0);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light BlueGreen", 33, 0x99CCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Ocean Green", 34, 0x669999);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Moss Green", 35, 0x336666);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dark Green", 36, 0x003333);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Forest Green", 37, 0x006633);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Grass Green", 38, 0x009933);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Wild Willow", 39, 0xB5CC61);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Kentucky Green", 40, 0x339966);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light Green", 41, 0x33CC66);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Spring Green", 42, 0x33CC33);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Turquoise", 43, 0x66FFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Sea Green", 44, 0x33CC99);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Faded Green", 45, 0x99CC99);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Ghost Green", 46, 0xCCFFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Mint Green", 47, 0x99FF99);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Army Green", 48, 0x669966);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Avocado Green", 49, 0x669933);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Martian Green", 50, 0x99CC33);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dull Green", 51, 0x99CC66);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Chartreuse", 52, 0x99FF00);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Moon Green", 53, 0xCCFF66);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Murky Green", 54, 0x333300);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Olive Drab", 55, 0x666633);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Khaki", 56, 0x999966);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Olive", 57, 0x999933);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Banana Yellow", 58, 0xCCCC33);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light Yellow", 59, 0xFFFF66);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Chalk", 60, 0xFFFF99);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Pale Yellow", 61, 0xFFFFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Brown", 62, 0x996633);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Red Brown", 63, 0xCC6633);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Gold", 64, 0xCC9933);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Autumn Orange", 65, 0xFF6633);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light Orange", 66, 0xFF9933);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Peach", 67, 0xFF9966);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Yellow", 68, 0xFFCC00);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Sand", 69, 0xFFCC99);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Walnut", 70, 0x663300);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Ruby Red", 71, 0x990000);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Brick Red", 72, 0xCC3300);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Tropical Pink", 73, 0xFF6666);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Soft Pink", 74, 0xFF9999);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Faded Pink", 75, 0xFFCCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dark Red", 76, 0x800000);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Crimson", 77, 0x993366);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Regal Red", 78, 0xCC3366);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Rose", 79, 0xCC3399);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Neon Red", 80, 0xFF0066);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Pink", 81, 0xFF6699);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Hot Pink", 82, 0xFF3399);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dusty Rose", 83, 0xCC6699);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Plum", 84, 0x660066);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Violet", 85, 0x990099);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light Violet", 86, 0xFF99FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Violet", 87, 0xCC66CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dusty Plum", 88, 0x996699);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Pale Purple", 89, 0xCC99CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Majestic Purple", 90, 0x9933CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Neon Purple", 91, 0xCC33FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Light Purple", 92, 0xCC66FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Twilight Violet", 93, 0x9966CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Easter Purple", 94, 0xCC99FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Purple", 95, 0x330066);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Grape", 96, 0x663399);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Blue Violet", 97, 0x9966FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Blue Purple", 98, 0x9900FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep River", 99, 0x6600CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Azure", 100, 0x6633FF);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Storm Blue", 101, 0x330099);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Deep Blue", 102, 0x3300CC);
        TEST_COLORI(hpl, LC_PROP_ENT_COLOR, "Dark Blue", 103, 0x000080);
        TEST_COLORT(hpl, LC_PROP_ENT_COLOR, "15,10,44", 0x0F0A2C);

        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Black", 0, 0x000000);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "90% Black", 1, 0x191919);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "80% Black", 2, 0x333333);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "70% Black", 3, 0x4D4D4D);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "60% Black", 4, 0x666666);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "50% Black", 5, 0x808080);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "40% Black", 6, 0x999999);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "30% Black", 7, 0xB3B3B3);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "20% Black", 8, 0xCCCCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "10% Black", 9, 0xE6E6E6);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "White", 10, 0xFFFFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Blue", 11, 0x0000FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Cyan", 12, 0x00FFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Green", 13, 0x00FF00);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Yellow", 14, 0xFFFF00);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Red", 15, 0xFF0000);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Magenta", 16, 0xFF00FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Purple", 17, 0x9900CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Orange", 18, 0xFF6600);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Pink", 19, 0xFF99CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dark Brown", 20, 0x663333);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Powder Blue", 21, 0xCCCCFF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Pastel Blue", 22, 0x9999FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Baby Blue", 23, 0x6699FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Electric Blue", 24, 0x6666FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Twilight Blue", 25, 0x6666CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Navy Blue", 26, 0x003399);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Navy Blue", 27, 0x000066);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Desert Blue", 28, 0x336699);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dodger Blue", 29, 0x1389FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Sky Blue", 30, 0x00CCFF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Ice Blue", 31, 0x99FFFF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Smalt Blue", 32, 0x0068D0);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light BlueGreen", 33, 0x99CCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Ocean Green", 34, 0x669999);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Moss Green", 35, 0x336666);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dark Green", 36, 0x003333);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Forest Green", 37, 0x006633);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Grass Green", 38, 0x009933);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Wild Willow", 39, 0xB5CC61);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Kentucky Green", 40, 0x339966);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light Green", 41, 0x33CC66);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Spring Green", 42, 0x33CC33);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Turquoise", 43, 0x66FFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Sea Green", 44, 0x33CC99);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Faded Green", 45, 0x99CC99);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Ghost Green", 46, 0xCCFFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Mint Green", 47, 0x99FF99);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Army Green", 48, 0x669966);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Avocado Green", 49, 0x669933);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Martian Green", 50, 0x99CC33);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dull Green", 51, 0x99CC66);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Chartreuse", 52, 0x99FF00);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Moon Green", 53, 0xCCFF66);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Murky Green", 54, 0x333300);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Olive Drab", 55, 0x666633);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Khaki", 56, 0x999966);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Olive", 57, 0x999933);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Banana Yellow", 58, 0xCCCC33);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light Yellow", 59, 0xFFFF66);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Chalk", 60, 0xFFFF99);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Pale Yellow", 61, 0xFFFFCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Brown", 62, 0x996633);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Red Brown", 63, 0xCC6633);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Gold", 64, 0xCC9933);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Autumn Orange", 65, 0xFF6633);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light Orange", 66, 0xFF9933);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Peach", 67, 0xFF9966);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Yellow", 68, 0xFFCC00);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Sand", 69, 0xFFCC99);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Walnut", 70, 0x663300);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Ruby Red", 71, 0x990000);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Brick Red", 72, 0xCC3300);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Tropical Pink", 73, 0xFF6666);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Soft Pink", 74, 0xFF9999);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Faded Pink", 75, 0xFFCCCC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dark Red", 76, 0x800000);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Crimson", 77, 0x993366);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Regal Red", 78, 0xCC3366);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Rose", 79, 0xCC3399);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Neon Red", 80, 0xFF0066);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Pink", 81, 0xFF6699);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Hot Pink", 82, 0xFF3399);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dusty Rose", 83, 0xCC6699);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Plum", 84, 0x660066);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Violet", 85, 0x990099);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light Violet", 86, 0xFF99FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Violet", 87, 0xCC66CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dusty Plum", 88, 0x996699);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Pale Purple", 89, 0xCC99CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Majestic Purple", 90, 0x9933CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Neon Purple", 91, 0xCC33FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Light Purple", 92, 0xCC66FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Twilight Violet", 93, 0x9966CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Easter Purple", 94, 0xCC99FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Purple", 95, 0x330066);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Grape", 96, 0x663399);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Blue Violet", 97, 0x9966FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Blue Purple", 98, 0x9900FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep River", 99, 0x6600CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Azure", 100, 0x6633FF);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Storm Blue", 101, 0x330099);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Deep Blue", 102, 0x3300CC);
        TEST_COLORI(hpl, LC_PROP_ENT_FCOLOR, "Dark Blue", 103, 0x000080);
        TEST_COLORT(hpl, LC_PROP_ENT_FCOLOR, "15,10,44", 0x0F0A2C);

        // Изменение цвета только через lcPropPutString если не задано ByBlock/ByLayer убирает наследование цвета
        assert(lcPropGetBool(hpl, LC_PROP_ENT_COLORBYLAYER) == 0);
        assert(lcPropGetBool(hpl, LC_PROP_ENT_FCOLORBYLAYER) == 0);

        lcDeleteDrawing(drawing);
}