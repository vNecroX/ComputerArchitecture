//#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int i, j, auxJ;
int x, y;

char input[10];
int auxVector[10];
int vector[10];

//int singleVecDer[10];

//int latVector[10];
int latPosVector[10][100];
int latCount[100];
int auxFather, fatherNum = 0;
int auxLatPos, latPosition = 0;

int dispVector[10];
int dispNum;

int orVector[10];
int countOne = 0;
int countSame = 0;
//bool flagContinue = false;


int fatherVec[10][100];
int vectorCount = 0;

int vectorGate[10][100];
int posDer[10];

void stringToInt(char ch[]);
void auxVecToVec(int aux[]);
void currentVector(int v[]);  

void storeVector(int vector[], int latPos);

void latencies(int v[]);

void halfAlgorithm();

void displace(int v[]);
void orGate(int fVec[], int dVec[]);

void reverseVec(int v[], int dNum);

void newFather(int nFather[]);

//void algorithm();

//void printDisp(int vDisp[10][100]);
//void printDer(int vDer[10][100]);

int main(){
    printf("C O L L I S I O N   V E C T O R: ");
    gets(input);

    stringToInt(input);
    currentVector(auxVector);

    auxVecToVec(auxVector);
    currentVector(vector);

    storeVector(vector, fatherNum);

    latencies(vector);

    halfAlgorithm();
    //printDisp(fatherVec);
    //printDer(vectorGate);

    return 0;
}

void stringToInt(char ch[]){
    for(i=0; i<6; i++)
        auxVector[i] = ch[i] - '0';
}

void auxVecToVec(int aux[]){
    for(x=0, y=5; x<6; x++, y--)
        vector[x] = aux[y];
}

void currentVector(int v[]){
    printf("\nC. vector:\t");

    for(i=0; i<6; i++)
        printf("%i", v[i]);

    printf("\n");
}

void storeVector(int v[], int fNum){
    printf("\nStored vector in [%i]: ", fNum);

    for(x=0; x<6; x++){
        fatherVec[fNum][x] = v[x];
        printf("%i", fatherVec[fNum][x]);
    }
}

void latencies(int v[]){
    //int auxJ;
    printf("\nLatencies: ");

    //j = 0;
    auxFather = fatherNum;
    auxLatPos = latPosition;

    for(x=0; x<6; x++){
        if(v[x] == 0){
            latPosVector[fatherNum][latPosition] = x;
            printf("%i ", latPosVector[fatherNum][latPosition]);
            //y++;
            latCount[fatherNum]++;
            latPosition++;
        }
    }
    printf("\nLatencies count: %i", latCount[fatherNum]);
}

void halfAlgorithm(){
    displace(vector);
    orGate(vector, dispVector);
}

void displace(int fVector[]){
    printf("\nDisplaced vector: ");

    //j = 0; //if to know when makes zero. . .

    dispNum = latPosVector[auxFather][auxLatPos];
    dispNum++;
    //j++;   //count to control increasement

    for(i=0; i<6; i++){
        dispVector[i] = fVector[dispNum + i];
        printf("%i", dispVector[i]);
    }
}

void orGate(int fVec[], int dVec[]){  //if to know when store the possible new father. . .
    
    printf("\nOr gate vector: ");

    for(j=0; j<6; j++){
        if((fVec[j] == 1) || (dVec[j] == 1)){
            orVector[j] = 1;
            countOne++;
        }
        else if((fVec[j] == 0) && (dVec[j] == 0))
            orVector[j] = 0;

        printf("%i", orVector[j]);
    }

    for(j=0; j<6; j++){
        if(fVec[j] == orVector[j])
            countSame++;
    }

    if(countOne != 6){
        if(countSame != 6){
            reverseVec(orVector, dispNum);
            //continue breeding. . .

            fatherNum++;
            storeVector(orVector, fatherNum);
            newFather(orVector);

            latPosition = 0;
            latencies(vector);
            displace(vector);
            orGate(vector, dispVector);

        }
        else{
            reverseVec(orVector, dispNum);


        }
    }
    else{
        reverseVec(orVector, dispNum);
        latCount[fatherNum]--;

        if(latCount[fatherNum] != 0){
            //printf("\n%i", latCount[fatherNum]);
            auxLatPos++;
            halfAlgorithm();
        }
    }
}

void reverseVec(int v[], int dNum){
    printf("\n");

    printf("%i ", dNum);
    for(x=5; x>-1; x--)
        printf("%i", v[x]);
}

void newFather(int nFather[]){
    for(i=0; i<6; i++)
        vector[i] = nFather[i];
}

void printDisp(int vDisp[10][100]){
    /*
    printf("\n");

    for(i=0; i<6; i++){
        for(j=0; j<6; j++)
            printf("%i", vDisp[j][i]);

        printf("\n");
    }
    */
}

void printDer(int vDer[10][100]){
    /*
    int auxCountLatPos;

    auxCountLatPos = countLatPos;

    printf("\n");

    for(i=0; i<countLatPos; i++){
        printf("%i ", posDer[i]);

        for(j=0; j<6; j++)
            printf("%i", vDer[j][i]);

        printf("\t");
    }
    */
}