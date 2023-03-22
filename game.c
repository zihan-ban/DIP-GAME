#include <math.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
void six(const char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    putchar(str[i]);
    fflush(stdout);
    usleep(50);
  }
}
void clear() { system("clear"); }
// Saveing Time in bin File
void t() {
  time_t current_time;
  current_time = time(NULL);
  FILE *file = fopen("database/time.bin", "wb");
  putw(current_time, file);
  fclose(file);
  return 0;
}
// Saveing Time In bin File
void y() {
  time_t current_time;
  current_time = time(NULL);
  FILE *file = fopen("database/squixtime.bin", "wb");
  putw(current_time, file);
  fclose(file);
  return 0;
}
// Saveing MineX Exp Time In Bin
void x() {
  time_t current_time;
  current_time = time(NULL);
  FILE *file = fopen("database/ItemExp/minexexp.bin", "wb");
  putw(current_time, file);
  fclose(file);
  return 0;
}
void d() {
  time_t current_time;
  current_time = time(NULL);
  FILE *file = fopen("database/ItemExp/xpboostexp.bin", "wb");
  putw(current_time, file);
  fclose(file);
  return 0;
}
// Adding Coin
void addcoin(int *data) {
  FILE *file1 = fopen("database/coin.bin", "rb");
  int num1 = getw(file1);
  int num2 = data;
  int num = num1 + num2;
  fclose(file1);
  FILE *file = fopen("database/coin.bin", "wb");
  putw(num, file);
  fclose(file);
  return 0;
}
// Show Coin
void coinx() {
  FILE *file = fopen("database/coin.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
  return 0;
}
// Converta To 0
void con() {
  FILE *file = fopen("database/coin.bin", "rb");
  int num = getw(file);
  fclose(file);
  if (num < 0) {
    addcoin(-1 * num);
  }
}
// Showing Name
void nam() {
  FILE *fp;
  char text[100];
  fp = fopen("database/name.txt", "r");
  while (fgets(text, 100, fp) != NULL) {
    printf("%s", text);
  }
  fclose(fp);
}
// Coin Flip Game
void game() {
  int g;
  int num = rand() % 2 + 1;
  clear();
  printf("                 ");
  six("Head Or Tail\n\n");
  six("        1 = Head * 2 = Tail * 69 = Home\n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  six("Enter Number : ");
  scanf("%d", &g);
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
  if (g == 69) {
    clear();
    system("./main");
    return 0;
  }
  if (num == 1) {
    six("\nDip Flipped The Coin And It Was Head\n");
  }
  if (num == 2) {
    six("\nDip Flipped The Coin And It Was Tail\n");
  }
  six("Your Choice : ");
  if (g == 1) {
    six("Head");
  }
  if (g == 2) {
    six("Tail");
  }

  if (g == num) {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━");
    addcoin(1000);
    six("\n1000 Coin Add To Your Account");
    six("\nCurrent Coin : ");
    con();
    coinx();
    printf("\n");
    int back5;
    printf("\nType 69 To Restart : ");
    scanf("%d", &back5);
    if (back5 == 69 || back5 != 69) {
      game();
    }
    return 0;
  }
  if (g != num) {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    six("            *You Fucked Up*");
    six("\n2000 Coin Removed From Your Account\n");
    addcoin(-2000);
    six("\nCurrent Coin : ");
    con();
    coinx();
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    int back5;
    printf("\nType 69 To Restart : ");
    scanf("%d", &back5);
    if (back5 == 69 || back5 != 69) {
      game();
    }
    return 0;
  }
}
// Squidx Game
void xp() {
  int g;
  int floor1, floor2;
  srand(time(0));
  floor1 = rand() % 2 + 1;
  do {
    floor2 = rand() % 2 + 1;
  } while (floor1 == floor2);
  clear();
  printf("                 ");
  six("Squidx(BETA)\n");
  six("\n             Choice Any Floor\n");
  six("\n      |-------------|    |-------------|  \n      |             |    "
      "|             |\n      |      1      |    |      2      |\n      |      "
      "       |    |             |\n      |-------------|    "
      "|-------------|\n\n\n");
  six("Enter Floor Number : ");
  scanf("%d", &g);
  //  printf("Your : %d\nFloor 1 : %d\nFloor 2 : %d",g,floor1,floor2);
  if (g == 1) {
    if (floor1 != g) {
      clear();
      printf("                 ");
      six("Squidx(BETA)\n");
      six("\n\n            *You Fucked Up*");
      six("\n2000 Coin Removed From Your Account");
      printf("\nCurrent Coin : ");
      addcoin(-2000);
      con();
      coinx();
      y();
      printf("\n\n*You Can't Play For 120 Second");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      int back6;
      printf("\nType 69 To Return Home : ");
      scanf("%d", &back6);
      if (back6 == 69 || back6 != 69) {
        clear();
        system("./main");
      }
    }
    if (floor1 == g) {
      clear();
      printf("                 ");
      six("Squidx(BETA)\n");
      six("\n        Nice Now Jump To Next Floor\n");
      six("\n1000 Coin Add To Your Account");
      printf("\n\nCurrent Coin : ");
      addcoin(1000);
      con();
      coinx();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      int back7;
      printf("\nType 69 To Continue  : ");
      scanf("%d", &back7);
      if (back7 == 69 || back7 != 69) {
        clear();
        xp();
      }
    }
  }

  if (g == 2) {
    if (floor2 != g) {

      clear();
      printf("                 ");
      six("Squidx(BETA)\n");
      six("\n\n            *You Fucked Up*");
      six("\n2000 Coin Removed From Your Account");
      printf("\nCurrent Coin : ");
      addcoin(-2000);
      con();
      coinx();
      y();
      printf("\n\n*You Can't Play For 120 Second");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      int back10;
      printf("\nType 69 To Return Home : ");
      scanf("%d", &back10);
      if (back10 == 69 || back10 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (floor2 == g) {
    clear();

    printf("                 ");
    six("Squidx(BETA)\n");
    six("\n       Nice Now Jump To Next Floor\n");
    six("\n1000 Coin Add To You Account");
    printf("\n\nCurrent Coin : ");
    addcoin(1000);
    con();
    coinx();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    int back8;
    printf("\nType 69 To Continue  : ");
    scanf("%d", &back8);
    if (back8 == 69 || back8 != 69) {
      clear();
      xp();
    }
  }
}
// Item Adding
   // Mine Adding
void minexadd(int *data) {
  FILE *file1 = fopen("database/item/minex.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/item/minex.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
  // XP Emp Adding
void xpboostadd(int *data) {
  FILE *file1 = fopen("database/item/xpboost.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/item/xpboost.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Item Showing
  // MineX Show
void minexshow() {
  FILE *file = fopen("database/item/minex.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
  // XP Emp Show
void xpboostshow() {
  FILE *file = fopen("database/item/xpboost.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Mining Item Add Void
// iron add void
void iron(int *data) {
  FILE *file1 = fopen("database/Mining/iron.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/iron.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Coal Add
void coal(int *data) {
  FILE *file1 = fopen("database/Mining/coal.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/coal.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Silver Add
void silver(int *data) {
  FILE *file1 = fopen("database/Mining/silver.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/silver.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Crimsteel Add
void crim(int *data) {
  FILE *file1 = fopen("database/Mining/crimsteel.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/crimsteel.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// gold add
void gold(int *data) {
  FILE *file1 = fopen("database/Mining/gold.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/gold.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Mythan
void mythan(int *data) {
  FILE *file1 = fopen("database/Mining/mythan.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/mythan.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// Magic
void magic(int *data) {
  FILE *file1 = fopen("database/Mining/magic.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/magic.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// End
// Mine Item Ammount Show
// iron Show
void ironshow() {
  FILE *file = fopen("database/Mining/iron.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// coal Show
void coalshow() {
  FILE *file = fopen("database/Mining/coal.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Silver Show
void silvershow() {
  FILE *file = fopen("database/Mining/silver.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Crimsteel Show
void crimshow() {
  FILE *file = fopen("database/Mining/crimsteel.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Gold Show
void goldshow() {
  FILE *file = fopen("database/Mining/gold.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Mythan Show
void mythanshow() {
  FILE *file = fopen("database/Mining/mythan.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Magic Show
void magicshow() {
  FILE *file = fopen("database/Mining/magic.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
//       End
// Xp Storeing
void xpstore(int *data) {
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int xp1 = getw(file1);
  int xp2 = data;
  int xp3 = xp1 + xp2;
  fclose(file1);
  FILE *file = fopen("database/Mining/Level/xp.bin", "wb");
  putw(xp3, file);
  fclose(file);
}
// Level Storing
void lvlstore(int *data) {
  FILE *file1 = fopen("database/Mining/Level/lvl.bin", "rb");
  int xp1 = getw(file1);
  int xp2 = data;
  int xp3 = xp1 + xp2;
  fclose(file1);
  FILE *file = fopen("database/Mining/Level/lvl.bin", "wb");
  putw(xp3, file);
  fclose(file);
}
// Next Level XP Store
void nxtxp(int *data) {
  FILE *file1 = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int xp1 = getw(file1);
  int xp2 = data;
  int xp3 = xp1 + xp2;
  fclose(file1);
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "wb");
  putw(xp3, file);
  fclose(file);
}
// Reset Xp
void reset(int *data) {
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int xp1 = getw(file1);
  int xp2 = data;
  int xp3 = xp1 - xp2;
  fclose(file1);
  FILE *file = fopen("database/Mining/Level/xp.bin", "wb");
  putw(xp3, file);
  fclose(file);
}
// Info Showing
// Show Xp
void xpshow() {
  FILE *file = fopen("database/Mining/Level/xp.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Show lvl
void lvlshow() {
  FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Show Next Xp Lvl
void nxtxpshow() {
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}
// Total Mineing
void total() {
  FILE *file = fopen("database/Mining/total.bin", "rb");
  int num = getw(file);
  fclose(file);
  printf("%d", num);
}

// Info Adding
// Adding Total Mining
void mineadd(int *data) {
  FILE *file1 = fopen("database/Mining/total.bin", "rb");
  int mine1 = getw(file1);
  int mine2 = data;
  int mine3 = mine1 + mine2;
  fclose(file1);
  FILE *file = fopen("database/Mining/total.bin", "wb");
  putw(mine3, file);
  fclose(file);
}
// ............
// Area Void...
// ............
// Iron Area
void ironarea() {
  clear();
  srand(time(NULL));
  int ironamm = rand() % 30 + 1;
  int randxp = rand() % 10 + 1;
  printf("                ");
  six("Iron Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  iron(ironamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Iron", ironamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Iron : ");
  ironshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Iron Area\n\n");
  printf("Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Iron Area\n\n");
  printf("   Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Iron Area\n\n");
  printf("     Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  ironshow();
  printf(" Iron \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    ironarea();
  }
}

// Coal Area
void coalarea() {
  clear();
  srand(time(NULL));
  int coalamm = rand() % 20 + 1;
  int randxp = rand() % 15 + 1;
  printf("                ");
  six("Coal Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  coal(coalamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Coal", coalamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Iron : ");
  ironshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Coal Area\n\n");
  printf("Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Coal Area\n\n");
  printf("   Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Coal Area\n\n");
  printf("     Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  coalshow();
  printf(" Coal \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    coalarea();
  }
}
// Silver Area
void silverarea() {
  clear();
  srand(time(NULL));
  int silveramm = rand() % 15 + 1;
  int randxp = rand() % 35 + 1;
  printf("                ");
  six("Silver Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  silver(silveramm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Silver", silveramm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Silver : ");
  silvershow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Silver Area\n\n");
  printf("Mining Starting In 4 Second\n");
  sleep(1);
  clear();
  printf("                ");
  printf("Silver Area\n\n");
  printf("   Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("                ");
  printf("Silver Area\n\n");
  printf("     Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("                ");
  six("Silver Area\n\n");
  printf("       Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  silvershow();
  printf(" Silver \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    silverarea();
  }
}
// Crimsteel Area
void crimsteelarea() {
  clear();
  srand(time(NULL));
  int crimsteelamm = rand() % 7 + 1;
  int randxp = rand() % 45 + 1;
  printf("                ");
  six("Crimsteel Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  crim(crimsteelamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Crimsteel", crimsteelamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Crimsteel : ");
  crimshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Crimsteel Area\n\n");
  printf("Mining Starting In 5 Second\n");
  sleep(1);
  clear();
  printf("               ");
  printf("Crimsteel Area\n\n");
  printf(" Mining Starting In 4 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Crimsteel Area\n\n");
  printf("  Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("             ");
  printf("Crimsteel Area\n\n");
  printf("   Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Crimsteel Area\n\n");
  printf("    Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  crimshow();
  printf(" Crimsteel \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    crimsteelarea();
  }
}
// Gold Area
void goldarea() {
  clear();
  srand(time(NULL));
  int goldamm = rand() % 5 + 1;
  int randxp = rand() % 70 + 1;
  printf("                ");
  six("Gold Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  gold(goldamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Gold", goldamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Gold : ");
  goldshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  six("Gold Area\n\n");
  printf("Mining Starting In 7 Second\n");
  sleep(1);
  clear();
  printf("               ");
  six("Gold Area\n\n");
  printf(" Mining Starting In 6 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Gold Area\n\n");
  printf("  Mining Starting In 5 Second\n");
  sleep(1);
  clear();
  printf("             ");
  printf("Gold Area\n\n");
  printf("   Mining Starting In 4 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Gold Area\n\n");
  printf("    Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("           ");
  printf("Gold Area\n\n");
  printf("     Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("          ");
  printf("Gold Area\n\n");
  printf("      Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  goldshow();
  printf(" Gold \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    goldarea();
  }
}
// Mythan
void mythanarea() {
  clear();
  srand(time(NULL));
  int mythanamm = rand() % 4 + 1;
  int randxp = rand() % 80 + 1;
  printf("                ");
  six("Mythan Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To\n ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  mythan(mythanamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Mythan", mythanamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Mythan : ");
  mythanshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Mythan Area\n\n");
  printf("Mining Starting In 9 Second\n");
  sleep(1);
  clear();
  printf("               ");
  printf("Mythan Area\n\n");
  printf(" Mining Starting In 8 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Mythan Area\n\n");
  printf("  Mining Starting In 7 Second\n");
  sleep(1);
  clear();
  printf("             ");
  printf("Mythan Area\n\n");
  printf("   Mining Starting In 6 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Mythan Area\n\n");
  printf("    Mining Starting In 5 Second\n");
  sleep(1);
  clear();
  printf("           ");
  printf("Mythan Area\n\n");
  printf("     Mining Starting In 4 Second\n");
  sleep(1);
  clear();
  printf("          ");
  printf("Mythan Area\n\n");
  printf("      Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("         ");
  printf("Mythan Area\n\n");
  printf("       Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("        ");
  printf("Mythan Area\n\n");
  printf("        Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  mythanshow();
  printf(" Mythan \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    mythanarea();
  }
}
// Magic Area
void magicarea() {
  clear();
  srand(time(NULL));
  int magicamm = rand() % 2 + 1;
  int randxp = rand() % 90 + 1;
  printf("                ");
  six("Magic Area\n\n");
  FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int nxxp = getw(file);
  fclose(file);
  FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
  int nowxp = getw(file1);
  fclose(file1);
  if (nowxp > nxxp) {
    reset(nowxp);
    lvlstore(1);
    nxtxp(50);
    printf("NOTIFICATION ALERT :\n You Have Level Up To\n ");
    lvlshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);
  }
  magic(magicamm);
  mineadd(1);
  xpstore(randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Mined %d Magic", magicamm);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("You Have Received %d XP", randxp);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Magic : ");
  magicshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  sleep(2);
  clear();
  printf("                ");
  printf("Magic Area\n\n");
  printf("Mining Starting In 10 Second\n");
  sleep(1);
  clear();
  printf("               ");
  printf("Magic Area\n\n");
  printf(" Mining Starting In 9 Second\n");
  sleep(1);
  clear();
  printf("              ");
  printf("Magic Area\n\n");
  printf("  Mining Starting In 8 Second\n");
  sleep(1);
  clear();
  printf("             ");
  printf("Magic Area\n\n");
  printf("   Mining Starting In 7 Second\n");
  sleep(1);
  clear();
  printf("            ");
  printf("Magic Area\n\n");
  printf("    Mining Starting In 6 Second\n");
  sleep(1);
  clear();
  printf("           ");
  printf("Magic Area\n\n");
  printf("     Mining Starting In 5 Second\n");
  sleep(1);
  clear();
  printf("          ");
  printf("Magic Area\n\n");
  printf("      Mining Starting In 4 Second\n");
  sleep(1);
  clear();
  printf("         ");
  printf("Magic Area\n\n");
  printf("       Mining Starting In 3 Second\n");
  sleep(1);
  clear();
  printf("        ");
  printf("Magic Area\n\n");
  printf("        Mining Starting In 2 Second\n");
  sleep(1);
  clear();
  printf("       ");
  printf("Magic Area\n\n");
  printf("         Mining Starting In 1 Second\n");
  sleep(1);
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  int back17;
  printf(" You Have Mined ");
  magicshow();
  printf(" Magic \n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("\nType 69 To Continue (96 = Home) : ");
  scanf("%d", &back17);
  if (back17 == 96) {
    clear();
    system("./main");
  }
  if (back17 == 69) {
    clear();
    magicarea();
  }
}
// ............
// Auto Mining Void...
// ............
// Iron Auto
void autoiron() {
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int ironamm = rand() % 30 + 1;
    int randxp = rand() % 10 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    iron(ironamm);
    mineadd(1);
    FILE *file69 = fopen("database/ItemExp/xpboostexp.bin", "rb");
    int num69 = getw(file69);
    fclose(file69);
    num69 = current - num69;
    int delay69 = 1200; // Xp Boost Exp
    int xpbo = (num69 - delay69) * -1;
    int xpx;
    if (0 < xpbo)
    {
   xpx = 2;   
    }
    else
    {
   xpx = 1;
    }
if(-5 < xpbo && 0 > xpbo)
{
	clear();
      printf("NOTIFICATION ALERT :\nXP Boost Expired. Use XP Boost Again To Get 2X XP");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	sleep(2);	
}
    int randxpx = randxp*xpx;
    xpstore(randxpx);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Iron \n", ironamm);
   if(xpx == 1)
    {
    printf("Received XP : %d", randxp);	
    	}
   if(xpx == 2)
    	{
    printf("Received XP : %d(2X XP) || Normal XP : %d",randxpx,randxp);
    	}
     printf("\nTotal Iron : ");
    ironshow();
    printf("\nMineX Expiring In %d Seconds", xp);
   if(20 > xpbo && 0 < xpbo)
   {
   printf("\nXP Boost Expiring In %d Seconds", xpbo);	
   }
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(3);

    if (3 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      autoiron();
    }
  }
}
void autocoal() // Coal
{
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int coalamm = rand() % 20 + 1;
    int randxp = rand() % 15 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    coal(coalamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Coal \n", coalamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Coal : ");
    coalshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(3);

    if (3 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      autocoal();
    }
  }
}
void autosilver() // Silver
{
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int coalamm = rand() % 15 + 1;
    int randxp = rand() % 35 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    coal(coalamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Silver \n", coalamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Silver : ");
    coalshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(4);

    if (4 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      autosilver();
    }
  }
}
void autocrim() {
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int crimamm = rand() % 7 + 1;
    int randxp = rand() % 45 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    crim(crimamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Crimsteel \n", crimamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Crimsteel : ");
    crimshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(5);

    if (5 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      autocrim();
    }
  }
}
void autogold() {
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int goldamm = rand() % 5 + 1;
    int randxp = rand() % 70 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    gold(goldamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Gold \n", goldamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Gold : ");
    goldshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(7);

    if (7 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      autogold();
    }
  }
}
void automythan() {
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int mythanamm = rand() % 4 + 1;
    int randxp = rand() % 80 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    mythan(mythanamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Mythan \n", mythanamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Mythan : ");
    mythanshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(9);

    if (9 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      automythan();
    }
  }
}
void automagic() {
  srand(time(NULL));
  for (int i = 0; i < i + 1; i++) {
    int magicamm = rand() % 2 + 1;
    int randxp = rand() % 90 + 1;
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    FILE *file3 = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file3);
    fclose(file3);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(5);
    }
    magic(magicamm);
    mineadd(1);
    xpstore(randxp);
    printf("\n\nTotal Mining ");
    total();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Mined %d Magic \n", magicamm);
    printf("Received XP : %d\n", randxp);
    printf("Total Magic : ");
    magicshow();
    printf("\nMineX Expiring In %d Seconds", xp);
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    sleep(10);

    if (10 > xp) {
      clear();
      printf("\nNOTIFICATION ALERT :\n MineX Expired. Use MineX Again To "
             "Continue");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
      system("./main");
    } else {
      automagic();
    }
  }
}

// Mining Add File
void mine111(int *data) {
  int num2 = data;
  FILE *file = fopen("database/item/xpboost.bin", "wb");
  putw(num2, file);
  fclose(file);
}
// Reset Section
// Reset Level
void relevel(int *data) {
  FILE *file1 = fopen("database/Mining/minelvl.bin", "rb");
  int xp1 = getw(file1);
  int xp2 = data;
  int xp3 = xp1 - xp2;
  fclose(file1);
  FILE *file = fopen("database/Mining/minelvl.bin", "wb");
  putw(xp3, file);
  fclose(file);
}
//
void resetmine() {
  // LVL Reset
  FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int num = getw(file);
  fclose(file);
  int lvlx = num;
  // Next Level Xp Reset
  FILE *file1 = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int num1 = getw(file1);
  fclose(file1);
  int lvlx1 = num1;
  // Xp Reset
  FILE *file2 = fopen("database/Mining/Level/xp.bin", "rb");
  int num2 = getw(file2);
  fclose(file2);
  int lvlx2 = num2;
  // Total Mining Reset
  FILE *file3 = fopen("database/Mining/total.bin", "rb");
  int num3 = getw(file3);
  fclose(file3);
  int lvlx3 = num3;
  lvlstore(lvlx - lvlx - lvlx + 1);
  mineadd(lvlx3 - lvlx3 - lvlx3);
  nxtxp(lvlx1 - lvlx1 - lvlx1 + 100);
  xpstore(lvlx2 - lvlx2 - lvlx2 + 1);
  printf("               ");
  six("Reset Mining Data\n\n");
  printf("Level And XP Reset Successful\n\n");
  six("New Mining Stats");
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  printf("Total Mining : ");
  total();
  printf("\n");
  printf("Level : ");
  lvlshow();
  printf("\n");
  printf("XP BAR : ");
  xpshow();
  printf("/");
  nxtxpshow();
  printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}
    // Menu Void Area
void miningmenu()
{
    printf("               ");
    six("Mining\n\n");
    printf("[1] Iron Area \n\n[2] Coal Area\n\n[3] Silver Area\n\n[4] "
           "Crimsteel Area\n\n[5] Gold Area\n\n[6] Mythan Area\n\n[7] Magic "
           "Area\n\n[8] Back\n\n");
    six("Enter Menu Number : ");
    int menu2;
    scanf("%d", &menu2);
  if (menu2 == 1) {
    ironarea();
  }
  if (menu2 == 2) {
    coalarea();
  }
  if (menu2 == 3) {
  FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 5;
    if (level1 >= minlevel) // Minimum Level
    {
      silverarea();
    } else {
    clear();
    printf("SYSTEM NOTIFICATION : \n");
      printf("You Need %d Mining Level To Access This Area", minlevel);
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    miningmenu();
    }
  }
  if (menu2 == 4) {
  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 10;
    if (level1 >= minlevel) // Minimum Level
    {
      crimsteelarea();
    } else {
    clear();
    printf("SYSTEM NOTIFICATION : \n");
      printf("You Need %d Mining Level To Access This Area", minlevel);
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    miningmenu();
    }
  }
  if (menu2 == 5) {
  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 20;
    if (level1 >= minlevel) // Minimum Level
    {
      goldarea();
    } else {
     clear();
    printf("SYSTEM NOTIFICATION : \n");
      printf("You Need %d Mining Level To Access This Area", minlevel);
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    miningmenu();
    }
  }

  if (menu2 == 6) {
  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 35;
    if (level1 >= minlevel) // Minimum Level
    {
      mythanarea();
    } else {
       clear();
    printf("SYSTEM NOTIFICATION : \n");
      printf("You Need %d Mining Level To Access This Area", minlevel);
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    miningmenu();
    }
  }

  if (menu2 == 7) {
 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 50;
    if (level1 >= minlevel) // Minimum Level
    {
      magicarea();
    } else {
        clear();
    printf("SYSTEM NOTIFICATION : \n");
      printf("You Need %d Mining Level To Access This Area", minlevel);
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    miningmenu();
    }
  }
  if (menu2 == 8) {
    clear();
    system("./main");
  }
} 
int main() {
  FILE *fp;
  FILE *fp1;
  char text[100];
  int menu;
  int menu1;
  int menu2;
  int menu3;
  int menu4;
  int menu5;
  int menu6;
  int menu7;
  int menu8;
  int menu9;
  int menu69;
  int coin69, xp69, lvl69, nxt69;
  char namex[100];
  printf("[1] My Profile\n\n[2] Daily Bonus\n\n[3] Games\n\n[4] Mining\n\n[5] "
         "Auto Mining\n\n[6] Inventory\n\n[7] Shop\n\n[8] Use Item\n\n[9] "
         "Settings\n\n");
  six("Enter Menu Number : ");
  scanf("%d", &menu);
  if (menu == 1) {
    clear();
    printf("                ");
    six("My Profile\n\n");
    six("Username: ");
    nam();
    six("\n\nTotal Coin : ");
    con();
    coinx();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
    int nxxp = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/Mining/Level/xp.bin", "rb");
    int nowxp = getw(file1);
    fclose(file1);
    if (nowxp > nxxp) {
      reset(nowxp);
      lvlstore(1);
      nxtxp(50);
      printf("NOTIFICATION ALERT :\n You Have Level Up To ");
      lvlshow();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      sleep(1);
    }
    six("Mining Stats|\n");
 printf("━━━━━━━━━━━━\n"); 
    printf("Total Mining : ");
    total();
    printf("\n");
    printf("Level : ");
    lvlshow();
    printf("\n");
    printf("XP BAR : ");
    xpshow();
    printf("/");
    nxtxpshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    int back1;
    printf("Type 69 To Return Home : ");
    scanf("%d", &back1);
    if (back1 == 69 || back1 != 69) {
      clear();
      system("./main");
    }
    return 0;
  }

  if (menu == 2) {
    FILE *file = fopen("database/time.bin", "rb");
    int num = getw(file);
    fclose(file);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 30;
    if (num > delay) {
      clear();
      printf("               Daily Bonus\n\n");
      six("1000 Coin Add To Your Account");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Preveous Coin : ");
      con();
      coinx();
      printf("\n━━━━━━━━━━━━━━");
      printf("\nCurrent Coin : ");
      addcoin(1000);
      con();
      coinx();
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Wait %d Second For Next Claim\n", delay);
      t();
      int back2;
      printf("\n\nType 69 To Return Home : ");
      scanf("%d", &back2);
      if (back2 == 69 || back2 != 69) {
        clear();
        system("./main");
      } else {
        printf("Fuck . Run Again");
      }
      return 0;
    } 
    else
    {
      clear();
      printf("SYSTEM NOTIFICATION : \n");
      six("Wait ");
      int cooldown = num - delay;
      printf("%d",cooldown*-1);
      six(" Second For Next Claim");
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      system("./main");
    }
  }
  if (menu == 3) {
    clear();
    printf("                ");
    six("Games\n\n");
    printf("[1] Coin Flip\n\n[2] Squidx(BETA)\n\n[3] Back\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu3);
  }
  if (menu3 == 1) {
    game();
  }

  if (menu3 == 2) {
    FILE *file = fopen("database/squixtime.bin", "rb");
    int num = getw(file);
    fclose(file);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 120;
    if (num > delay) {
      xp();
    } else {
      printf("\n\n");
      six("Wait ");
      printf("%d-", num - delay);
      six(" Second For Next Game\n");
      int back11;

      printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Restart : ");
      scanf("%d", &back11);
      if (back11 == 69 || back11 != 69) {
        clear();
        system("./main");
      }
    }
  }

  if (menu3 == 3) {
    clear();
    system("./main");
  }
  if (menu == 4) {
  	clear();
 miningmenu();
  }
  if (menu == 5) {
    FILE *file = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file);
    fclose(file);
    time_t current;
    current = time(NULL);
    num = current - num;
    int delay = 600; // Exp Time
    int xp = (num - delay) * -1;
    if (0 < xp) {
      clear();
      printf("               ");
      six("Auto Mining\n\n");
      printf("[1] Iron Area \n\n[2] Coal Area\n\n[3] Silver Area\n\n[4] "
             "Crimsteel Area\n\n[5] Gold Area\n\n[6] Mythan Area\n\n[7] Magic "
             "Area\n\n[8] Back\n\n");
      six("Enter Menu Number : ");
      scanf("%d", &menu7);
    } else {
     
      clear();
      printf("SYSTEM NOTIFICATION : \n");
      printf("To Activate The Auto Mining Feature\nPlease Active Minex.\n");
     printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");	
        system("./main");
    }
  }
  if (menu7 == 1) {
    clear();
    printf("                ");
    six("Iron Area[Auto]\n\n");
        FILE *file69 = fopen("database/ItemExp/xpboostexp.bin", "rb");
    int num69 = getw(file69);
    fclose(file69);
    time_t current;
    current = time(NULL);
    num69 = current - num69;
    int delay69 = 120; // XP Boost Exp
    int xpbo = (num69 - delay69) * -1;
    int xpx;
    if (0 < xpbo)
    {
   xpx = 2;   
    }
    else
    {
   xpx = 1;
    }
if(xpx ==2)
{
printf("NOTIFICATION ALERT :\nSince You Have An Active XP Boost\nYou Will Receive An Additional 2X XP Boost");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");	
    sleep(2);
}
    autoiron();
  }
  if (menu7 == 2) {
    clear();
    printf("                ");
    six("Coal Area[Auto]\n\n");
    autocoal();
  }
  if (menu7 == 3) {
  	  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 5;
    if (level1 >= minlevel) // Minimum Level
    {
      clear();
      printf("                ");
      six("Silver Area[Auto]\n\n");
      autosilver();
    } else {
      printf("\nYou Need %d Mining Level To Access This Area", minlevel);
      int back3;
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Return Home : ");
      scanf("%d", &back3);
      if (back3 == 69 || back3 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu7 == 4) {
  	  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 10;
    if (level1 >= minlevel) // Minimum Level
    {
      clear();
      printf("                ");
      six("Crimsteel Area[Auto]\n\n");
      autocrim();
    } else {
      printf("\nYou Need %d Mining Level To Access This Area", minlevel);
      int back3;
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Return Home : ");
      scanf("%d", &back3);
      if (back3 == 69 || back3 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu7 == 5) {
  	  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 20;
    if (level1 >= minlevel) // Minimum Level
    {
      clear();
      printf("                ");
      six("Gold Area[Auto]\n\n");
      autogold();
    } else {
      printf("\nYou Need %d Mining Level To Access This Area", minlevel);
      int back3;
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Return Home : ");
      scanf("%d", &back3);
      if (back3 == 69 || back3 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu7 == 6) {
  	  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 35;
    if (level1 >= minlevel) // Minimum Level
    {
      clear();
      printf("                ");
      six("Mythan Area[Auto]\n\n");
      automythan();
    } else {
      printf("\nYou Need %d Mining Level To Access This Area", minlevel);
      int back3;
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Return Home : ");
      scanf("%d", &back3);
      if (back3 == 69 || back3 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu7 == 7) {
  	  	 FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int level1 = getw(file);
  fclose(file);
    int minlevel = 50;
    if (level1 >= minlevel) // Minimum Level
    {
      clear();
      printf("                ");
      six("Magic Area[Auto]\n\n");
      automagic();
    } else {
      printf("\nYou Need %d Mining Level To Access This Area", minlevel);
      int back3;
      printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
      printf("Type 69 To Return Home : ");
      scanf("%d", &back3);
      if (back3 == 69 || back3 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu7 == 8) {
    clear();
    system("./main");
  }
  if (menu == 6) {
    clear();
    printf("               ");
    six("Inventory");
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Iron : ");
    ironshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Coal : ");
    coalshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Silver : ");
    silvershow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Crimsteel : ");
    crimshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Gold : ");
    goldshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Mythan : ");
    mythanshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("Magic : ");
    magicshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("\t\t   | Usable Item |");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("MineX : ");
    minexshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    printf("XP Boost : ");
    xpboostshow();
    printf("\n━━━━━━━━━━━━━━━━\n");
    int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }

  if (menu == 7) {
    clear();
    printf("               ");
    six("Shop\n\n");
    six("[1] Buy\n\n[2] Sell\n\n[3] Back\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu4);
  }
  if (menu4 == 1) {
    clear();
    printf("               ");
    six("BUY\n\n");
    printf("[1] Buy MineX [1000 Coin]\n\n[2] Buy XP Boost [5000 Coin]\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu5);
  }

  // MineX
  if (menu5 == 1) {
    clear();
    FILE *file = fopen("database/coin.bin", "rb");
    int coin = getw(file);
    fclose(file);
    printf("         ");
    six("BUY MineX [1000 Coin]\n\n");
    int minex;
    int amount;
    six("Current Coin : ");
    con();
    coinx();
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Buy : ");
    scanf("%d", &minex);
    int totalcoin = -1000 * amount;
    if (minex == 69) {

      if (totalcoin * -1 <= coin) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        minexadd(amount);
        addcoin(totalcoin);
        printf("You Have Purchased %d MineX\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Removed From Your Account\n", totalcoin * -1);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Coin To Buy");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Coin\n", (totalcoin * -1) - coin);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
 if(menu5 == 2)
 {
    clear();
    FILE *file = fopen("database/coin.bin", "rb");
    int coin = getw(file);
    fclose(file);
    printf("         ");
    six("BUY XP Boost [5000 Coin]\n\n");
    int xpbx;
    int amount;
    six("Current Coin : ");
    con();
    coinx();
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Buy : ");
    scanf("%d", &xpbx);
    int totalcoin = -5000 * amount;
    if (xpbx == 69) {

      if (totalcoin * -1 <= coin) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        xpboostadd(amount);
        addcoin(totalcoin);
        printf("You Have Purchased %d XP Boost\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Removed From Your Account\n", totalcoin * -1);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Coin To Buy");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Coin\n", (totalcoin * -1) - coin);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
 }
  if (menu4 == 2) // Sell Menu
  {
    clear();
    printf("               ");
    six("SELL\n\n");
    six("[1] Iron [");
    ironshow();
    printf("]\n\n");
    printf("[2] Coal [");
    coalshow();
    printf("]\n\n");
    six("[3] Silver [");
    silvershow();
    printf("]\n\n");
    printf("[4] Crimsteel [");
    crimshow();
    printf("]\n\n");
    six("[5] Gold [");
    goldshow();
    printf("]\n\n");
    six("[6] Mythan [");
    mythanshow();
    printf("]\n\n");
    printf("[7] Magic [");
    magicshow();
    printf("]\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu6);
  }
  if (menu6 == 1) // Iron Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/iron.bin", "rb");
    int ironx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Iron\n\n");
    printf("Current Iron : ");
    ironshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totaliron = 5 * amount; // iron price
    if (confirm == 69) {

      if (amount <= ironx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        iron(amount * -1);
        addcoin(totaliron);
        printf("You Have Sold %d Iron\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totaliron);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Iron To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Iron\n", amount - ironx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 2) // Coal Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/coal.bin", "rb");
    int coalx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Coal\n\n");
    printf("Current Coal : ");
    coalshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalcoal = 10 * amount; // Coal price
    if (confirm == 69) {

      if (amount <= coalx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        coal(amount * -1);
        addcoin(totalcoal);
        printf("You Have Sold %d Coal\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalcoal);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Coal To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Coal\n", amount - coalx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 3) // Silver Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/silver.bin", "rb");
    int silverx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Silver\n\n");
    printf("Current Silver : ");
    silvershow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalsilver = 20 * amount; // Silver price
    if (confirm == 69) {

      if (amount <= silverx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        silver(amount * -1);
        addcoin(totalsilver);
        printf("You Have Sold %d Silver\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalsilver);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Silver To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Silver\n", amount - silverx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 4) // Crimsteel Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/crimsteel.bin", "rb");
    int crimx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Crimsteel\n\n");
    printf("Current Crimsteel : ");
    crimshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalcrim = 30 * amount; // Crimsteel price
    if (confirm == 69) {

      if (amount <= crimx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        crim(amount * -1);
        addcoin(totalcrim);
        printf("You Have Sold %d Crimsteel\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalcrim);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Crimsteel To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Crimsteel\n", amount - crimx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 5) // Gold Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/gold.bin", "rb");
    int goldx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Gold\n\n");
    printf("Current Gold : ");
    goldshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalgold = 10 * amount; // Gold price
    if (confirm == 69) {

      if (amount <= goldx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        gold(amount * -1);
        addcoin(totalgold);
        printf("You Have Sold %d Gold\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalgold);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Gold To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Gold\n", amount - goldx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 6) // Mythan Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/mythan.bin", "rb");
    int mythanx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Mythan\n\n");
    printf("Current Mythan : ");
    mythanshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalmythan = 10 * amount; // Mythan price
    if (confirm == 69) {

      if (amount <= mythanx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        mythan(amount * -1);
        addcoin(totalmythan);
        printf("You Have Sold %d Mythan\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalmythan);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Mythan To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Mythan\n", amount - mythanx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu6 == 7) // Magic Sell Section
  {
    clear();
    FILE *file = fopen("database/Mining/magic.bin", "rb");
    int magicx = getw(file);
    fclose(file);
    clear();
    printf("           ");
    six("SELL Magic\n\n");
    printf("Current Magic : ");
    magicshow();
    printf("\n");
    int confirm;
    int amount;
    printf("\n\nEnter Amount : ");
    scanf("%d", &amount);
    printf("\nType 69 To Sell : ");
    scanf("%d", &confirm);
    int totalmagic = 10 * amount; // Magic price
    if (confirm == 69) {

      if (amount <= magicx) {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        magic(amount * -1);
        addcoin(totalmagic);
        printf("You Have Sold %d Magic\n", amount);
        printf("━━━━━━━━━━━━━━━━━\n");
        printf("%d Coin Add To Your Account\n", totalmagic);
        six("Current Coin : ");
        con();
        coinx();
        printf("\n");
        sleep(4);
        clear();
        system("./main");
      } else {
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("You Don't Have Enough Magic To Sell");
        printf("\n━━━━━━━━━━━━━━━━━\n");
        printf("You Need More %d Magic\n", amount - magicx);
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        sleep(4);
        clear();
        system("./main");
      }
    }
  }
  if (menu4 == 3) {
    clear();
    system("./main");
  }
  if (menu == 8) {
    clear();
    FILE *file = fopen("database/item/minex.bin", "rb");
    int amm = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/item/xpboost.bin", "rb");
    int ammxp = getw(file1);
    fclose(file1);
    printf("               ");
    six("Use Item\n\n");
    printf("[1] MineX [%d]\n\n", amm);
    printf("[2] XP Boost [%d]\n\n", ammxp);
    printf("[3] Active Items\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu8);
  }
  if (menu8 == 1) {
    clear();
    printf("               ");
    six("Use MineX\n\n");
    FILE *file = fopen("database/item/minex.bin", "rb");
    int amm = getw(file);
    fclose(file);
if(amm > 0)
    {
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("You Have Used A MineX\n");
    x();
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current MineX : ");
    minexadd(-1);
    minexshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Expiring In 10 Minutes/600 Seconds");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    	}
    	    else
    {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("You Currently Don't Have This Item");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");	
    }
    int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == back16) {
      clear();
      system("./main");
    }
      
  }
if(menu8 == 2)
{
    clear();
    printf("               ");
    six("Use XP Boost\n\n");
    FILE *file1 = fopen("database/item/xpboost.bin", "rb");
    int ammxp = getw(file1);
    fclose(file1);
if(ammxp > 0)
   { printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("You Have Used A XP Boost\n");
    d();
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current XP Boost : ");
    xpboostadd(-1);
    xpboostshow();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Expiring In 20 Minutes/1200 Seconds");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    }
    else
    {
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("You Currently Don't Have This Item");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");	
    }
    int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
}
  if (menu8 == 3) {
    FILE *file = fopen("database/ItemExp/minexexp.bin", "rb");
    int num = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/ItemExp/xpboostexp.bin", "rb");
    int num1 = getw(file1);
    fclose(file);
    time_t current;
    current = time(NULL);
    num = current - num;
    num1 = current - num1;
    int delay = 600; // Minex Exp Time
    int xpdelay = 1200; // Xp Boost Exp Time
    clear();
    printf("               ");
    int xp = (num - delay) * -1;
    int xpbo = (num1 - xpdelay) * -1;
    six("Active Items\n\n");
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("MineX\n");
    if (0 < xp) {
      printf("      Expiring In %d Seconds", xp);
    } else {
      printf("       Use MineX First");
    }
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("XP Boost\n");
    if (0 < xpbo) {
      printf("      Expiring In %d Seconds", xpbo);
    } else {
      printf("       Use XP Boost First");
    }
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if (menu == 9) // Settings
  {
    clear();
    printf("               ");
    six("Settings\n\n");
    printf("[1] Change Username\n\n[2] Reset Mining Data\n\n[3] Back\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu1);
  }
  if (menu == 69) // Dev Mode
  {
    clear();
    printf("               ");
    six("Dev Mode\n\n");
    printf("[1] Add Coin\n\n[2] Add Level\n\n[3] Add XP\n\n[4] Add Next Level "
           "XP\n\n[5] Add Item\n\n[6] Back\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu69);
  }
  if (menu69 == 1) {
    clear();
  FILE *file = fopen("database/coin.bin", "rb");
  int num = getw(file);
  fclose(file);
    printf("               ");
    six("Add Coin\n\n");
  	printf("NOTE: Type 69 To Reset\n");
  	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current Coin : ");
    con();
    coinx();
    six("\nEnter Coin Amount : ");
    scanf("%d", &coin69);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  	if(coin69 == 69)
   {
   	int coin68 = num*-1;
   	addcoin(coin68);
   printf("Your Coin Has Been Reset\n");
   	}
  else {
    addcoin(coin69);
    printf("%d Coin Add To Your Account\n", coin69);
  	}
    printf("Current Coin : ");
    con();
    coinx();
    printf("\n");
    int back16;
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if (menu69 == 2) {
    clear();
  FILE *file = fopen("database/Mining/Level/lvl.bin", "rb");
  int num = getw(file);
  fclose(file);
    printf("               ");
    six("Add Level\n\n");
    printf("NOTE: Type 69 To Reset\n");
  	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current Level : ");
    lvlshow();
    six("\nEnter Level : ");
    scanf("%d", &lvl69);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
 if(lvl69 == 69)
 {
 	int lvl68 = num*-1;
 	lvlstore(lvl68+1);
 printf("Your Level Has Been Reset\n");	
 }
 else {
    lvlstore(lvl69);
    printf("%d Level Add To Your Account\n", lvl69);
    }
    printf("Current Level : ");
    lvlshow();
    printf("\n");
    int back16;
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if (menu69 == 3) {
    clear();
    printf("               ");
    FILE *file = fopen("database/Mining/Level/xp.bin", "rb");
  int num = getw(file);
  fclose(file);
    six("Add XP\n\n");
    printf("NOTE: Type 69 To Reset\n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current XP : ");
    xpshow();
    printf("/");
    nxtxpshow();
    six("\nEnter XP Amount : ");
    scanf("%d", &xp69);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  if(xp69 == 69)
  {
  	int xp68 = num*-1;
  	xpstore(xp68+1);
 printf("Your XP Has Been Reset\n"); 	
  }  
  else {
  	xpstore(xp69);
    printf("%d XP Add To Your Account\n", xp69);
    }
    printf("Current XP : ");
    xpshow();
    printf("/");
    nxtxpshow();
    printf("\n");
    int back16;
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if (menu69 == 4) {
    clear();
    printf("               ");
   FILE *file = fopen("database/Mining/Level/nextlvlxp.bin", "rb");
  int num = getw(file);
  fclose(file);
  six("Add Next Level XP\n\n");
  printf("NOTE: Type 69 To Reset\n");
  printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current Next Level XP : ");
    nxtxpshow();
    printf("\n");
    six("Enter Next Level XP : ");
    scanf("%d", &nxt69);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
if(nxt69 == 69)
{
  int nxt68 = num*-1;
  nxtxp(nxt68+100);
  printf("Your Next Level XP Has Been Reset\n");
} else {
    nxtxp(nxt69);
    printf("%d Next Level XP Add To Your Account\n", nxt69);
    }
    printf("Current Next Level XP : ");
    nxtxpshow();
    printf("\n");
    int back16;
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if(menu69 ==5)
  {
    clear();
    FILE *file = fopen("database/item/minex.bin", "rb");
    int amm = getw(file);
    fclose(file);
    FILE *file1 = fopen("database/item/xpboost.bin", "rb");
    int ammxp = getw(file1);
    fclose(file1);
    printf("               ");
    six("Add Item\n\n");
    printf("[1] MineX [%d]\n\n", amm);
    printf("[2] XP Boost [%d]\n\n", ammxp);
    printf("[3] Back To Home\n\n");
    six("Enter Menu Number : ");
    scanf("%d", &menu9);
    }
if(menu9 == 1)
{
	clear();
    printf("               ");
  FILE *file = fopen("database/item/minex.bin", "rb");
  int num = getw(file);
  fclose(file);
    six("Add MineX\n\n");
    printf("NOTE: Type 69 To Reset\n");
  	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current MineX : ");
    minexshow();
   printf("\nEnter Amount : ");
   int amm;
   scanf("%d",&amm);
printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
  if(amm == 69)
  {
  int minexamm = num*-1;
  	minexadd(minexamm);
  printf("Your MineX Has Been Reset\n");		
  }
  else{
  	minexadd(amm);
  	printf("%d MineX Add To Your Account\n", amm);
  	}
  	printf("Current MineX : ");
  minexshow();
   printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━");
   int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
}
}
if(menu9 == 2)
{
	clear();
    printf("               ");
  FILE *file = fopen("database/item/xpboost.bin", "rb");
  int num = getw(file);
  fclose(file);
    six("Add XP Boost\n\n");
    printf("NOTE: Type 69 To Reset\n");
  	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("Current XP Boost : ");
    xpboostshow();
   printf("\nEnter Amount : ");
   int amm;
   scanf("%d",&amm);
printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
   if(amm == 69)
   {
   	int xpboostamm = num*-1;
   	xpboostadd(xpboostamm);
   	printf("Your XP Boost Has Been Reset\n"); 
   	}
   	else
   	{
   xpboostadd(amm);
printf("%d XP Boost Add To Your Account\n", amm);
   	}
   printf("Current XP Boost : ");
  xpboostshow();
   printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━");
   int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main"); 
      }
}
if(menu9 == 3)
{
      clear();
      system("./main");	
}
  if (menu69 == 6) {
    clear();
    system("./main");
  }
  if (menu1 == 1) {
    clear();
    printf("               ");
    six("Change Username\n\n");
    six("Enter New Username : ");
    scanf("%s", &namex);
    FILE *fp;
    fp = fopen("database/name.txt", "w");
    fprintf(fp, "%s", namex);
    fclose(fp);
    printf("\n\n");
    six("Congratulations Your Name Successcessfully Set As ");
    nam();
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    int back16;
    printf("\nType 69 To Return Home : ");
    scanf("%d", &back16);
    if (back16 == 69 || back16 != 69) {
      clear();
      system("./main");
    }
  }
  if (menu1 == 2) {
    int back30;
    printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    printf("\nType 69 To Confirm : ");
    scanf("%d", &back30);
    if (back30 != 69) {
      clear();
      system("./main");
    }
    if (back30 == 69) {
      clear();
      resetmine();
      int back31;
      printf("\nType 69 To Return Home : ");
      scanf("%d", &back31);
      if (back31 == 69 || back31 != 69) {
        clear();
        system("./main");
      }
    }
  }
  if (menu1 == 3) {
    clear();
    system("./main");
  }
   if (menu > 9) {
    clear();
    printf("SYSTEM NOTIFICATION : \n");
    printf("Please Use A Valid Menu Number.\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");	
    system("./main");
  }
}
