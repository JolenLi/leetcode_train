//
// Created by Jolen on 2021/10/16.
//

//
// Created by Jolen on 2021/10/15.
//

#include <stdio.h>

#include <stdlib.h>

#include <math.h>


#define MAX_SIZE 11 //染色体二进制编码位数
#define MAX_PAIR 10 //染色体条数

typedef struct Chrom        //结构体类型，为单个染色体结构
{
    short int bit[MAX_SIZE];//一共5bit来对染色体进行编码，其中1位为符号位，取值范围0~31
    int fit;//适应度
    double rfit;//选择概率，即所占的百分比
    double cfit;//累计概率
} chrom;

//定义将会用到的函数
void evpop(chrom popcurrent[MAX_PAIR]);//进行种群的初始化
int btod(chrom popcurrent);//二进制->十进制
int fitness(int x);//计算适应度
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]);//轮盘赌法算子选择
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR]);//锦标赛法算子选择
void crossover(chrom popnext[MAX_PAIR]);//交叉操作
void mutation(chrom popnext[MAX_PAIR]);//突变
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]); //循环进行选择交叉变异
void print_bit(chrom popcurrent[MAX_SIZE]);//输出整条染色体的编码情况
int main()//主函数
{
    chrom popcurrent[MAX_PAIR];//初始种群规模
    chrom popnext[MAX_PAIR];//更新后种群规模
    int loop, Max;

//    printf("请输入迭代数：");
//    scanf("%d", &loop);
    printf("\n初始化种群为：\n");
    evpop(popcurrent);//初始化种群
    mian_loop(popcurrent, popnext);//进行循环
    Max = btod(popcurrent[0]);//期望已完成收敛
    printf("\n最终结果为：%d\n", Max);
    return 0;
}

void evpop(chrom popcurrent[MAX_PAIR]) //函数：随机生成初始种群：
{
    int i, j, value;
    int random;
    double sum = 0;

    for (j = 0; j < MAX_PAIR; j++) //从染色体的第1个基因到第6个
    {
        for (i = 0; i < MAX_SIZE; i++) {
            random = rand(); //产生一个随机值
            random = random % 2; //随机产生0或1
            popcurrent[j].bit[i] = random; //随机产生染色体上每一个值
        }
        popcurrent[j].fit = fitness(btod(popcurrent[j])); //计算染色体适应度值
        sum = sum + popcurrent[j].fit;

//        printf("popcurrent[%d]=%d%d%d%d%d   value=%d    fitness = %d\n",j,popcurrent[j].bit[0],popcurrent[j].bit[1],popcurrent[j].bit[2],popcurrent[j].bit[3],popcurrent[j].bit[4],value,popcurrent[j].fit);
        //输出整条染色体的编码情况
    }
    print_bit(popcurrent);//输出整条染色体的编码情况
    //计算适应值的百分比，改参数是在用轮盘赌选择法时需要用到的
    for (j = 0; j < MAX_PAIR; j++) {
        popcurrent[j].rfit = popcurrent[j].fit / sum;
        popcurrent[j].cfit = 0;//初始化
    }
    printf("\n");
}

void print_bit(chrom popcurrent[MAX_SIZE]) {
    for (int j = 0; j < MAX_PAIR; j++) {
        printf("pop[%d]=", j);
        for (int i = 0; i < MAX_SIZE; i++) {
            printf("%d", popcurrent[j].bit[i]);
        }
        printf("\tvalue=%d\tfitness = %d\n", btod(popcurrent[j]), fitness(btod(popcurrent[j])));
    }
}

int btod(chrom popcurrent) //二进制->十进制
{
    int d = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        d = d + popcurrent.bit[i] * pow(2, MAX_SIZE - 1 - i);
    }
    return d;
}

int fitness(int x)//求个体的适应度
{
    unsigned int fit = 0; // 计数器
    for (fit = 0; x; x >>= 1) // 循环移位
        fit += x & 1; // 如果当前位是1，则计数器加1
    return fit;
}

//基于轮盘赌法进行染色体选择（算子选择）
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR])//计算概率
{
    int men;
    int i, j;
    double p; //生成4个0~1的随机值
    double sum = 0.0; //find the total fitness of the population
    long int seed = 12345;

    for (men = 0; men < MAX_PAIR; men++)//计算总适应度
        sum = sum + popcurrent[men].fit;


    for (men = 0; men < MAX_PAIR; men++)//计算选择概率
        popcurrent[men].rfit = popcurrent[men].fit / sum;

    //计算累计概率
    popcurrent[0].cfit = popcurrent[0].rfit;
    for (men = 1; men < MAX_PAIR; men++) {
        popcurrent[men].cfit = popcurrent[men - 1].cfit + popcurrent[men].rfit;
    }

//    for (i = 0; i < MAX_PAIR; i++)//输出累计概率（调试用）
//    {
//        printf("popcurrent[%d].cfit=%f\n", i, popcurrent[i].cfit);
//    }

    for (i = 0; i < MAX_PAIR; i++)//生成若干个0~1随机数，根据累计概率进行选择（轮盘赌法核心）
    {//产生0~1之间的随机数
        p = rand() / (float)(RAND_MAX);
//        printf("random is %f\n", p);//输出随机数（调试用）
        if (p < popcurrent[0].cfit)
            popnext[i] = popcurrent[0];
        else
            for (j = 0; j < MAX_PAIR - 1; j++)
                if (popcurrent[j].cfit <= p && p < popcurrent[j + 1].cfit)
                    popnext[i] = popcurrent[j + 1];

        popnext[i].fit = fitness(btod(popnext[i]));//计算下一代染色体的适应度
    }
//    printf("选择个体:\n");
//    print_bit(popnext);

}


//基于锦标赛法进行染色体选择（算子选择）
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR]) {
    //
}

//交叉操作
void crossover(chrom popnext[MAX_PAIR]) {
    double pc = 0.9;//进行交叉的概率
    for (int i = 1; i < MAX_PAIR; i++) {
        if ((rand() / (float)(RAND_MAX)) < pc) {
            int pos = rand() % MAX_SIZE;
            int temp = popnext[i].bit[pos];
            popnext[i].bit[pos] = popnext[i - 1].bit[pos];
            popnext[i - 1].bit[pos] = temp;
        }
    }

    for (int i = 0; i < MAX_PAIR; i++) {
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }

//    printf("交叉后:\n");
//    print_bit(popnext);

}

//变异操作
void mutation(chrom popnext[MAX_PAIR]) {
    int i, j;//第i个染色体的第j个基因

    if ((rand() % 100) < 20)//即5%的几率产生变异
    {
        i = rand() % MAX_PAIR;//对应某一个染色体
        j = rand() % MAX_SIZE;//对应染色体上的基因
        if (popnext[i].bit[j] == 0)
            popnext[i].bit[j] = 1;
        else
            popnext[i].bit[j] = 0;
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }
//    printf("变异后:\n");
//    print_bit(popnext);
}

//循环函数
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]) {
    int i, j;
//    int loop = INTMAX_MAX;
    int loop = 999999;
    for (i = 0; i < loop; i++) {

        pickchroms_Roulette(popcurrent, popnext);//选择for(i = 0; i < MAX_PAIR ; i++)//打印轮盘赌法选择出的下一代染色体
        crossover(popnext);//交叉
        mutation(popnext);//变异
        printf("第%d次迭代：\n", i + 1);
        print_bit(popnext);
        for (j = 0; j < MAX_PAIR; j++)//更新下一代
            popcurrent[j] = popnext[j];
        int finish = 0;
        for (j = 0; j < MAX_PAIR; j++)//更新下一代
            if (popcurrent[j].fit == 11)
                finish = 1;
        if (finish){
            printf("\n第%d次迭代完成任务", i + 1);
            break;
        }



    }
}
