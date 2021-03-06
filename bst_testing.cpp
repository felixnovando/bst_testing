#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Data{
	char code[10];
	char name[100];
	char course[100];
	Data *left, *right;
}*root;

struct Data* createPeople(char code[], char name[], char course[]){
	Data *curr = (Data*)malloc(sizeof(Data));
	strcpy(curr->code,code);
	strcpy(curr->name,name);
	strcpy(curr->course,course);
	curr->left = curr->right = NULL;
	return curr;
}

Data* insert(Data *root, char code[], char name[], char course[]){
	if(root==NULL){
		return createPeople(code,name,course);
	}
	else{
		//smaller
		if(strcmp(name,root->name)<=0){
			root->left = insert(root->left,code,name,course);
		}
		//bigger
		else if(strcmp(name,root->name)>0){
			root->right = insert(root->right,code,name,course);
		}
	}
	return root;
}

void print_list(Data *curr){
	if(curr==NULL){
		return;
	}
	print_list(curr->left);
	printf("%s | %s | %s\n",curr->code,curr->name,curr->course);
	print_list(curr->right);
}

int search(Data *root, char name[], int count){
	printf("--> ");
	if(root==NULL){
		printf("not found\n");
		return 0;
	}
	else{
		if(strcmp(name,root->name)<0){
			printf("left ");
			return search(root->left,name,count+1);
		}
		else if(strcmp(name,root->name)>0){
			printf("right ");
			return search(root->right,name,count+1);
		}
		else{
			printf("found\n%s | %s | %s\n\n",root->code,root->name,root->course);
			return count;
		}
	}
}

int main(){
	
	//awal
	root = insert(root,"D6325","Noprianto","CB:Agama");
	root = insert(root,"D1119","Noor Rachmat","CB:Agama");
	root = insert(root,"D3027","PONIJAN","CB:Agama");
	root = insert(root,"D3046","CHRISTIAN SIREGAR","CB:Agama");
	root = insert(root,"D3702","SUKRON MA'MUN","CB:Agama");
	root = insert(root,"D4564","Simon Mangatur Tampubolon","CB:Agama");
	root = insert(root,"D5050","Jamson Siallagan","CB:Agama");
	root = insert(root,"D5689","Daulat Marulitua","CB:Agama");
	root = insert(root,"D1526","Syaeful Karim","Algorithm Design and Analysis");
	root = insert(root,"D2632","Zulfany Erlisa Rasjid","Algorithm Design and Analysis");
	root = insert(root,"D3087","AFAN GALIH SALMAN","Algorithm Design and Analysis");
	root = insert(root,"D4689","Rulyna","Algorithm Design and Analysis");
	root = insert(root,"D4692","Mayliana","Algorithm Design and Analysis");
	root = insert(root,"D5677","Indrabudhi Lokaadinugroho","Algorithm Design and Analysis");
	root = insert(root,"D5387","Harvianto","Algorithm Design and Analysis");
	root = insert(root,"D5550","Fanny","Algorithm Design and Analysis");
	root = insert(root,"D6298","Ruslan","Algorithm Design and Analysis");
	root = insert(root,"D2626","Karto Iskandar","Artificial Intelligence");
	root = insert(root,"D6241","Noprianto","Artificial Intelligence");
	root = insert(root,"D1026","S. Liawatimena","Artificial Intelligence");
	root = insert(root,"D1159","Diaz D. Santika","Artificial Intelligence");
	root = insert(root,"D2634","Eko Budi Purwanto","Artificial Intelligence");
	root = insert(root,"D3803","YAYA HERYADI","Artificial Intelligence");
	root = insert(root,"D4730","Rini Wongso","Artificial Intelligence");
	root = insert(root,"D6375","Heri Ngarianto","Artificial Intelligence");
	root = insert(root,"D5627","I Gede Putra Kusuma Negara","Artificial Intelligence");
	
	while(true){
		system("cls");
		puts("Lecturer List");
		print_list(root);
		char name[100]={};
		puts("");
		puts("Input the name to be searched (full name)");
		printf("name : ");
		scanf("%[^\n]",name); getchar();
		puts(name);
		printf("search : ");
		int many = search(root,name,1);
		if(many>0) printf("Total loop : %d\n",many);		
		
		puts("");
		puts("again ? YES | NO");
		do{
			printf("choice : ");
			scanf("%s",name);
			getchar();
		}while(!strcmp(name,"YES")==0 && !strcmp(name,"NO")==0);
		if(strcmp(name,"NO")==0) break;
	}
	
	return 0;
}
