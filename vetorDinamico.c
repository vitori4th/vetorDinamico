#include <stdio.h>
#include <stdlib.h>
//feito com professor Hokama

int * addVet(int *v, int *endSize, int * endMaxSize, int e){
	int i;
	if(*endSize<*endMaxSize){
		
		v[*endSize]=e;
		*endSize= *endSize+1;
		return v;
		
	}else{
		int tamanhoAtual= *endMaxSize;
		int * vaux= (int *) malloc(2* tamanhoAtual *sizeof(int));
		
		for(i=0;i<*endSize;i++){
			vaux[i]=v[i];
		}
		
		vaux[*endSize]=e;
		*endSize= *endSize+1;
		*endMaxSize= 2 * tamanhoAtual;
		free(v);
		
		return vaux;
	}
	
}

void printVet(int *v, int size, int maxSize){
	int i;
	printf("Vetor tem %d elementos, e %d de tamanho alocado\n", size, maxSize);
	
	for(i=0;i<size;i++){
		printf("%d, ", v[i]);
	}
		printf("\n");
}

int * initVet(int *endSize, int *endMaxSize){
	int * vet = (int *) malloc( 4 *sizeof(int));
	*endSize=0;
	*endMaxSize=4;
	
	return vet;
}

int find(int *v, int size,int e){
	int i;
	for(i=0;i<size;i++){
		if(v[i]==e) return i;
		
	}
	return -1;
}

int * removeVet(int *v, int * endSize, int * endMaxSize, int e){
	int i;
	int pos=find(v,*endSize,e);
	if(pos==-1) return v;
	
	for(i=pos+1; i<*endSize;i++){
		v[i-1]=v[i];
	}
	*endSize=*endSize-1;
	
	//Ficar com - de 1/4 elementos
	if(*endSize *4 < *endMaxSize){
		int tamanhoAtual=*endMaxSize;
		int * vaux= (int *) malloc((tamanhoAtual/2) * sizeof(int));
		for(i=0;i<*endSize;i++){
			vaux[i]=v[i];
		}
		*endMaxSize=(tamanhoAtual/2);
		
		free(v);
		return vaux;
	}
	return v;
}

int main(){
	int size;
	int maxSize;
	int pos;
	int *vet;
	
	vet = initVet(&size,&maxSize);
	
	printVet(vet,size,maxSize);
	
	vet= addVet(vet, &size, &maxSize,3);
	vet= addVet(vet, &size, &maxSize,7);
	vet= addVet(vet, &size, &maxSize,5);
	vet= addVet(vet, &size, &maxSize,1);
	vet= addVet(vet, &size, &maxSize,3);
					
	printVet(vet,size,maxSize);
	
	pos=find(vet, size,1);
	if(pos!=-1){
		printf("Encontrei o 1, na posição %d\n",pos);
	}else{
		printf("Não encontrei\n");
	}
	
	pos=find(vet, size,10);
	if(pos!=-1){
		printf("Encontrei o 10, na posição %d\n",pos);
	}else{
		printf("Não encontrei o 10\n");
	}
	
	vet=removeVet(vet,&size,&maxSize,3);
	vet=removeVet(vet,&size,&maxSize,5);
	vet=removeVet(vet,&size,&maxSize,1);
	vet=removeVet(vet,&size,&maxSize,7);
	
	printVet(vet,size,maxSize);
	
	free(vet);
	return 0;
}
