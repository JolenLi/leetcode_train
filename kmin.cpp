#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define MAX_SIZE 11
#define MAX_PAIR 10

typedef struct Chrom//结构体类型，为单个染色体结构
{
    short int bit[MAX_SIZE];
    double fit;//适应度
    double rfit;//选择概率
    double cfit;//累计概率
} chrom;

void evpop(chrom popcurrent[MAX_PAIR]);//进行种群的初始化
int btod(chrom popcurrent);//二进制->十进制
double fitness(int x);//计算适应度
void Elite(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]);//轮盘赌法算子选择
void crossover(chrom popCurrent[MAX_PAIR], chrom popnext[MAX_PAIR]);//交叉操作
void mutation(chrom popnext[MAX_PAIR]);//突变
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]); //循环进行选择交叉变异
void print_bit(chrom popcurrent[MAX_SIZE]);//输出整条染色体的编码情况

int main()//主函数
{
    chrom popcurrent[MAX_PAIR];//初始种群规模
    chrom popnext[MAX_PAIR];//更新后种群规模
    printf("\n初始化种群为：\n");
    evpop(popcurrent);//初始化种群
    mian_loop(popcurrent, popnext);//进行循环
    return 0;
}

void evpop(chrom popcurrent[MAX_PAIR]) //函数：随机生成初始种群：
{
    int i, j, value;
    int random;
    double sum = 0;
    srand(time(NULL));
    for (j = 0; j < MAX_PAIR; j++) {
        for (i = 0; i < MAX_SIZE; i++) {
            random = rand(); //产生一个随机值
            random = random % 2; //随机产生0或1
            popcurrent[j].bit[i] = random; //随机产生染色体上每一个值
        }
        popcurrent[j].fit = fitness(btod(popcurrent[j])); //计算染色体适应度值
        sum = sum + popcurrent[j].fit;
    }
    print_bit(popcurrent);//输出整条染色体的编码情况

    for (j = 0; j < MAX_PAIR; j++) {
        popcurrent[j].rfit = popcurrent[j].fit / sum;
        popcurrent[j].cfit = 0;//初始化
    }
    printf("\n");
}


void print_bit(chrom popcurrent[MAX_SIZE]) {
    double min_fit = 10000;
    chrom minChrom;
    for (int j = 0; j < MAX_PAIR; j++) {
        if(min_fit>popcurrent[j].fit){
            min_fit=popcurrent[j].fit;
            minChrom=popcurrent[j];
        }
//        min_fit = min_fit > popcurrent[j].fit ? popcurrent[j].fit : min_fit;
//        printf("pop[%d]=", j);
        for (int i = 0; i < MAX_SIZE; i++) {
//            printf("%d", popcurrent[j].bit[i]);
        }
//        printf("\tfitness = %f\n", fitness(btod(popcurrent[j])));
    }
    printf("pop=");
    for (int i = 0; i < MAX_SIZE; i++)
            printf("%d",minChrom.bit[i]);
    printf(" fitness:%f\n\n", min_fit);
}

int btod(chrom popcurrent) //二进制->十进制
{
    int d = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        d = d + popcurrent.bit[i] * pow(2, MAX_SIZE - 1 - i);
    }
    return d;
}

double fitness(int x)//求个体的适应度
{
    double sqr[MAX_SIZE];
    double g1 = 0, g2 = 0;
    for (int j = 0; j < MAX_SIZE; j++) sqr[j] = sqrt(j + 1);
    for (double i : sqr) {
        if ((x & 1) == 1) {
            g1 += i;
        } else {
            g2 += i;
        }
        x >>= 1;
    }
    return abs(g1 - g2);
}


chrom chose_ind(chrom popcurrent[MAX_PAIR]) {
    int men;
    int i, j;
    double p;
    double sum = 0.0;
    chrom ans= popcurrent[0];
    int n = 30;
    for (men = 0; men < MAX_PAIR; men++)//计算总适应度
        sum = sum + (n - popcurrent[men].fit);
    for (men = 0; men < MAX_PAIR; men++)//计算选择概率
        popcurrent[men].rfit = (n - popcurrent[men].fit) / sum;

    //计算累计概率
    popcurrent[0].cfit = popcurrent[0].rfit;
    for (men = 1; men < MAX_PAIR; men++) {
        popcurrent[men].cfit = popcurrent[men - 1].cfit + popcurrent[men].rfit;
    }

    p = rand() / (float) (RAND_MAX);
    if (p < popcurrent[0].cfit)
        ans = popcurrent[0];
    else
        for (j = 0; j < MAX_PAIR - 1; j++)
            if (popcurrent[j].cfit <= p && p < popcurrent[j + 1].cfit)
                ans = popcurrent[j + 1];
    ans.fit = fitness(btod(ans));//计算下一代染色体的适应度
    return ans;
}






void Elite(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]) {
    popnext[0] = popcurrent[0];
    for (int i = 0; i < MAX_PAIR; i++)//精英保留
    {
        if (popnext[0].fit > popcurrent[i].fit)
            popnext[0] = popcurrent[i];
    }
}

//交叉操作
void crossover(chrom popCurrent[MAX_PAIR], chrom popnext[MAX_PAIR]) {
    double pc = 0.9;//进行交叉的概率
    srand(time(NULL));
    for (int i = 1; i < MAX_PAIR; i++) {
        if ((rand() / (float) (RAND_MAX)) > pc) {
            popnext[i] = chose_ind(popCurrent);
        } else {
            chrom x = chose_ind(popCurrent), y = chose_ind(popCurrent);
            int pos = rand() % MAX_SIZE;
            for (int j = pos; j < MAX_SIZE; j++) {
                int temp = x.bit[j];
                x.bit[j] = y.bit[j];
                y.bit[j] = temp;
            }
            popnext[i] = x;
            if (i + 1 == MAX_PAIR)
                break;
            popnext[i + 1] = y;
            i++;
        }
    }
    for (int i = 0; i < MAX_PAIR; i++) {
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }

}

//变异操作
void mutation(chrom popnext[MAX_PAIR]) {
    srand(time(NULL));
    for (int i = 1; i < MAX_PAIR; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if ((rand() % 10) < 5) {
//                int j = rand() % MAX_SIZE;
                if (popnext[i].bit[j] == 0)
                    popnext[i].bit[j] = 1;
                else
                    popnext[i].bit[j] = 0;
            }
        }
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }

}

void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]) {

    int i, j;
    int loop = 1000;
    //FILE* fp;
    //fopen_s(&fp, "Result.scv", "w");
    for (i = 0; i < loop; i++) {
        Elite(popcurrent, popnext);
        crossover(popcurrent, popnext);//交叉
        mutation(popnext);//变异
        printf("第%d次迭代：\n", i + 1);
        print_bit(popnext);
        //if (fp) {
        //    fprintf(fp, "%d\t%d\t%1f\n", i + 1, (int)max_fit, avg_fit);
        //}
        for (j = 0; j < MAX_PAIR; j++)//更新下一代
            popcurrent[j] = popnext[j];
        int finish = 0;
        for (j = 0; j < MAX_PAIR; j++)
            if (popcurrent[j].fit == MAX_SIZE)
                finish = 1;
        if (finish) {
            printf("\n第%d次迭代完成任务", i + 1);
            break;
        }
    }
}
