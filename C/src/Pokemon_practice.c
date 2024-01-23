#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//(1)定義一個enum 代表寶可夢的屬性(火:Fire 水:Water 草:Grass)
typedef enum
{
    Fire,
    Water,
    Grass,
}Attribute;

//(2)定義一個結構 包含名字(name) 攻擊力(atk) 血量(hp)
//                防禦(def) 滿血量(max_hp) 等級(lv) 屬性(attr)
typedef struct
{
    char name[20],type[10]; /*type為讓使用者輸入種類*/
    int atk,def,max_hp,hp,lv;
    Attribute attr;
}Pokemon;


/*
升等資訊表
        maxhp   atk def
Fire       50    30   5
Water      50    15  10
Grass     100    15   5
*/
//(3)升等
void LvUp(Pokemon *winLevelUP)
{
    switch(winLevelUP -> attr){
        case Fire:
            winLevelUP -> max_hp += 50;
            winLevelUP -> hp = winLevelUP -> max_hp;/*升級=回血*/
            winLevelUP -> atk += 30;
            winLevelUP -> def += 5;
            winLevelUP -> lv += 1;
            break;
        case Water:
            winLevelUP -> max_hp += 50;
            winLevelUP -> hp = winLevelUP -> max_hp;
            winLevelUP -> atk += 15;
            winLevelUP -> def += 10;
            winLevelUP -> lv += 1;
            break;
        case Grass:
            winLevelUP->max_hp+=100;
            winLevelUP -> hp = winLevelUP -> max_hp;
            winLevelUP -> atk += 15;
            winLevelUP -> def += 5;
            winLevelUP -> lv += 1;
            break;
        default:
            break;
    }
    return;
}

//(4)依攻擊力由高而低排序
void sortPokemon(Pokemon *totalPokemon,int totalnum)
{
    int i,j;
    Pokemon tempPokemon;
    for(j=totalnum-1;j>=0;j--){
        for(i=j;i>0;i--){
            if((totalPokemon+i)->atk >= (totalPokemon+(i-1))->atk){
                tempPokemon = *(totalPokemon + i);      /*將totalPokemon+i 所指的值給 tempPokemon*/
                *(totalPokemon + i) = *(totalPokemon + (i-1));
                *(totalPokemon + (i-1)) = tempPokemon;
            }
            else{
                continue;
            }
        }
    }
    return;
}

Pokemon monsterMaker()
{
    Pokemon monster;
    monster.atk=rand()%50+100;
    monster.attr=rand()%3;
    switch(monster.attr){
        case Fire:
            strcpy(monster.type,"Fire");
            break;
        case Water:
            strcpy(monster.type,"Water");
            break;
        case Grass:
            strcpy(monster.type,"Grass");
            break;
        default:
            break;
    }
    monster.def=rand()%20+85;
    monster.lv=rand()%10;
    monster.max_hp=rand()%50+400;
    monster.hp=monster.max_hp;
    sprintf(monster.name,"monster%d",rand()%10);
    return monster;
}

//戰鬥的副程式
void fight(Pokemon *totalPokemon,int totalnum)
{
    Pokemon monster = monsterMaker();
    Pokemon nowFighter;
    sortPokemon(totalPokemon,totalnum);
    int j;
    for(j=0;j<totalnum;j++){
        (totalPokemon+j)->hp = (totalPokemon+j)->max_hp;/*全回血*/
    }
    int i=0,mondamge=0,figdamge=0;
    printf("Find %s - atk: %d hp: %d def: %d lv: %d attr: %s\n",monster.name,monster.atk,monster.hp,monster.def,monster.lv,monster.type);
    do{
        int flag = 0;
        nowFighter = *(totalPokemon+i); /*取第i個Pokemon 複製一份到 nowFighter*/
        switch(monster.attr){/*計算傷害 屬性相剋增傷 */
            case Fire:
                switch(nowFighter.attr){
                    case Fire:
                        mondamge = monster.atk - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    case Water:
                        mondamge = monster.atk - nowFighter.def;    //不知道需不需要衰減
                        figdamge = nowFighter.atk * 1.5 - monster.def;
                        break;
                    case Grass:
                        mondamge = monster.atk * 1.5 - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    default:
                        break;
                }
                break;
            case Water:
                switch(nowFighter.attr){
                    case Fire:
                        mondamge = monster.atk * 1.5 - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    case Water:
                        mondamge = monster.atk - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    case Grass:
                        mondamge = monster.atk - nowFighter.def;
                        figdamge = nowFighter.atk * 1.5 - monster.def;
                        break;
                    default:
                        break;
                }
                break;
            case Grass:
                switch(nowFighter.attr){
                    case Fire:
                        mondamge = monster.atk - nowFighter.def;
                        figdamge = nowFighter.atk *1.5 - monster.def;
                        break;
                    case Water:
                        mondamge = monster.atk *1.5 - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    case Grass:
                        mondamge = monster.atk - nowFighter.def;
                        figdamge = nowFighter.atk - monster.def;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        if(mondamge<0){/*傷害小於 0 代表 無法破防*/
            mondamge = 0;
        }
        if(figdamge<0){
            figdamge = 0;
        }
        while(flag != 1 ){
            printf("%s cause %d damage to %s\n",nowFighter.name,figdamge,monster.name);
            monster.hp -= figdamge;
            printf("%s cause %d damage to %s\n",monster.name,mondamge,nowFighter.name);
            nowFighter.hp -= mondamge;
            if(monster.hp<=0){
                printf("Win!!!\n");
                *(totalPokemon+i) = nowFighter; /*用nowFighter 把 totalPokemon+i 替換掉*/
                LvUp((totalPokemon+i));/*讓獲勝的Pokemon升等*/
                return;
            }
            if(nowFighter.hp<=0){
                printf("My Pokemon %s lose.\n",nowFighter.name);
                nowFighter.hp = 0;
                *(totalPokemon+i) = nowFighter;
                flag = 1;
                i += 1; /*更換下一隻*/
                totalnum -= 1;/*存活量-1*/
            }
        }
        if(flag == 1){
            continue;
        }
    }while(totalnum>0);/*總數為0時玩家全軍覆沒*/

    /*
    (5)用MonsterMonker 新增一隻怪物，並將我方寶可夢都回滿血
    (6)完成攻擊(注意剋屬會增加1.5倍的攻擊力)
       攻擊程序如下:
         1.計算我方會對敵方造成的傷害
         2.敵方扣血，並顯示扣血量
         3.若敵方已死，我方勝利，同時及殺敵人的寶可夢提升一等
         4.若敵方未死，計算敵方對我方造成的傷害
         5.我方扣血，並顯示扣血量
         6.若我方未死，返回第一步
         7.若我方已死，派出下一隻寶可夢進行戰鬥
       對敵方造成的傷害 = 攻擊方基礎攻擊力*攻擊方對敵方屬性增傷 - 敵方防禦
       剋屬只有三種情況 水->火 火->草 草->水
    */
    return;

}


//(7)顯示寶可夢的資訊
void ShowPokemonInformation(Pokemon *ownPokemon, int total)
{
    int i;
    for(i=0;i<total;i++){
        printf("%d %s - atk: %d hp: %d def: %d lv: %d attr: %s\n",i+1,(ownPokemon+i)->name,(ownPokemon+i)->atk,(ownPokemon+i)->hp,(ownPokemon+i)->def,(ownPokemon+i)->lv,(ownPokemon+i)->type);
    }
    return;
}

int main()
{
    Pokemon*myPokemon;  //這句不要動，這個是存放寶可夢資訊的陣列
    srand(20180326);    //這句也不要動
    int num,i,job;
    printf("Please inpt numbers of Pokemon:");
    scanf("%d",&num);
    myPokemon = (Pokemon *)calloc(num, sizeof(Pokemon));
    for(i=0;i<num;i++){
        printf("Please input name,atk,hp,def,lv,attr:");
        scanf("%s%d%d%d%d%s",(myPokemon+i)->name,&(myPokemon+i)->atk,&(myPokemon+i)->max_hp,&(myPokemon+i)->def,&(myPokemon+i)->lv,(myPokemon+i)->type);
        (myPokemon+i)->hp = (myPokemon+i)->max_hp;
        if(strcmp((myPokemon+i)->type,"Fire") == 0){
            (myPokemon+i) -> attr = Fire;
        }
        else if(strcmp((myPokemon+i)->type,"Water") == 0){
            (myPokemon+i) -> attr = Water;
        }
        else if(strcmp((myPokemon+i)->type,"Grass") == 0){
            (myPokemon+i) -> attr = Grass;
        }
        else{
            printf("wrong attr Please input this Pokemon again\n");
            i-=1;
            continue;
        }
    }
    printf("\n\n");
    printf("Please choose function(1.Show Pokemon Information 2.Fight 3.Exit)");
    while(scanf("%d",&job)!=EOF){
        switch(job){
            case 1:
                ShowPokemonInformation(myPokemon,num);
                printf("\n\n");
                break;
            case 2:
                fight(myPokemon,num);
                printf("\n\n");
                break;
            case 3:
                free(myPokemon);
                return 0;
            default:
                break;
        }
        printf("Please choose function(1.Show Pokemon Information 2.Fight 3.Exit)");
    }
    /*(8)輸入我方寶可夢的數量，並使用動態記憶體產生寶可夢陣列*/
    /*(9)輸入我方寶可夢的資訊(名字 攻擊力 血量 防禦力 等級 屬性)*/
    /*(10)建議一個迴圈並顯示選單(1.顯示寶可夢資料 2.戰鬥 3.離開程式)*/
    /*    選單使用switch case 選擇要的功能*/
    /*(11)選擇"3.離開程式"時，歸還動態陣列的記憶體*/

}
