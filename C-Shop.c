#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define LEN sizeof(shop)

typedef struct shoping {
	char barcode[20];      //条形码
	char name[20];         //名字
	float price;           //价格
	int count;             //数量
	struct shoping *next;
} shop;

void welcome() {            //欢迎函数
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *            欢迎使用zhazha自助结账系统         *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}

int verify() {               //   验证码
	int num;
	srand(time(0));         //防止伪随机数 时间复杂度
	char node[7];     //node[6]='\0';
	char node_[6];
	char eng[60]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i=0; i<6; i++) {
		num=rand()%60+0;
		node[i]=eng[num];  //验证码
	}
	node[6]='\0';     //解决bug
	printf("    验证码为:%s    ",node);
	printf("请输入验证码:");
	scanf("%s",node_);
	if(strcmp(node,node_)==0) {
		return 1;
	} else {
		return 2;
	}
}

int lading () {    //登陆函数
	int i=1;      //计数3次结束
	while(i) {
		int j;//   接受验证码信息
		welcome();
		printf("                       * * * * * * 登陆 * * * * * *\n");
		char name_[20];
		char name[20];
		char password_[20];
		char password[20];
		FILE *fname=fopen("username.txt","r");
		if(fname!=NULL) {
			fscanf(fname,"%s",name_);                 //读取文件中的name
		} else {
			printf("用户名文件打开失败!!!\n");
		}
		fclose(fname);
		FILE *fpassword=fopen("userpassword.txt","r");
		if(fpassword!=NULL) {
			fscanf(fpassword,"%s",password_);           //读取文件中的password
		} else {
			printf("密码文件打开失败!!!\n");
		}
		fclose(fpassword);
		printf("    请输入name:");
		scanf("%s",name);
		printf("\n");
		printf("    请输入password:");
		scanf("%s",password);
		printf("\n");
		j=verify();
		if(strcmp(name,name_)==0  &&  strcmp(password,password_)==0) {
			if(j==1) {
				printf("\n    验证成功!!!\n");
				printf("* * * * * * * * * * * * * 登陆成功 * * * * * * * * * * * *\n \n \n \n");
				return 1;
				break;
			} else if(j==2) {
				printf("\n    验证失败!!!\n");
				printf("* * * * * * * * *登陆失败，请重新登陆 * * * * * * * * * * * * * *\n \n \n \n");
				Sleep(1000);
			}
		} else {
			if(i>0 && i<3)
				printf("* * * * * * * * *账号或密码错误,登陆失败，请重新登陆 * * * * * * * * * * * * * *\n \n \n \n");
			if((i++)==3) {
				printf("* * * * * * * * * 登陆失败，请重启系统后重试 * * * * * * * * * *\n \n \n \n");
				i=0;
				return 0;
			}
		}
		system("pause");
		system("cls");
	}
}

void byebye() {   //再见函数
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *            感谢使用zhazha自助结账系统         *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}

void emnu() {       //菜单函数
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *           (1) 增加购物车中的商品              *\n");   //条形码 名字 价格 必须一致
	printf("                *           (2) 删除购物车中的商品              *\n");   //名字  数量
	printf("                *           (3) 搜索购物车中的商品数量          *\n");   //名字
	printf("                *           (4) 更改购物车中的商品数量或价格    *\n");   //名字
	printf("                *           (5) 对购物车中商品进行排序          *\n");	 //sort
	printf("                *           (6) 查看购物车                      *\n");   //遍历链表
	printf("                *           (7) 结账                            *\n");   //遍历链表
	printf("                *           (8) 打印小票                        *\n");   //遍历文件
	printf("                *           (9) 更改账号密码                    *\n");   //读写文件
	printf("                *           (0) 退出本次结账                    *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void changenp() {  //更改账号密码
	printf("输入1改账号  输入2改密码 \n");
	char scan[200];
	while(1) {
		scanf("%s",scan);
		if(scan[0]>='0' && scan[1]<='9') {
			if(scan[1]=='\0') {
				break;
			}
		}
		printf("输入指令错误!!!从新输入!!!\n");
	}
	switch(scan[0]) {
		case '1':
			printf("请输入新账号:");
			char name1[20];
			scanf("%s",name1);
			printf("请再次输入新账号:");
			char name2[20];
			scanf("%s",name2);
			if(strcmp(name1,name2)==0) {
				FILE *fname=fopen("username.txt","w+");
				if(fname!=NULL) {
					fputs(name1,fname);
				} else {
					printf("账号文件打开失败!!!");
				}
				fclose(fname);
				printf("更改成功!!!\n你的新账号为:%s\n",name2);
				printf("请重新登陆!!!\n");
				system("pause");
				system("cls");
				byebye();
				exit(0);
			} else {
				printf("更改失败，两次账号输入不同!!!\n");
			}
			break;
		case '2':
			printf("请输入新密码:");
			char password1[20];
			scanf("%s",password1);
			printf("请再次输入密码:");
			char password2[20];
			scanf("%s",password2);
			if(strcmp(password1,password2)==0) {
				FILE *fpassword=fopen("userpassword.txt","w+");
				if(fpassword!=NULL) {
					fputs(password1,fpassword);
				} else {
					printf("密码文件打开失败\n");
				}
				fclose(fpassword);
				printf("更改成功!!!\n你的新密码为:%s\n",password2);
				printf("请重新登陆!!!\n");
				system("cls");
				system("pause");
				byebye();
				exit(0);
			} else {
				printf("更改失败，两次密码输入不同!!!\n");
			}
		default:
			printf("输入的指令不正确，请重新输入!!!\n");
			break;
	}
}

shop *creat() {                  //创建链表   空链表头
	shop *head=(shop*)malloc(LEN);
	head->next=NULL;
	return head;
}

void check(shop *head) {            //结账      销毁链表
	shop *check=head->next;
	shop *del_;
	float price=0.0;
	if(check==NULL) {
		printf("购物车中无货!!!\n");
		return ;
	}
	FILE *fp=fopen("小票.txt","w+");     //打开文件    打印小票
	if(fp!=NULL) {
		fprintf(fp,"zhazha自动结账\n\n\n\n");
		while(check) {
			printf("条形码:%s 商品名称:%s 商品价格:%.2f 商品的数量：%d\n",check->barcode,check->name,check->price,check->count);
			price=price+check->price*check->count;
			fprintf(fp,"条形码:%s",check->barcode);
			fprintf(fp,"名称:%s\n",check->name);
			fprintf(fp,"价格:%.2f\n",check->price);         //保存商品信息
			fprintf(fp,"数量:%d\n\n",check->count);
			del_=check;
			check=check->next;
			free(del_);		  //销毁链表
		}
		del_=NULL;            //使del_有指向
		head->next=NULL;      //销毁链表只剩下头
		printf("\n合计:%.2f",price);
		float many;
		printf("\n实收:");
		scanf("%f",&many);
		while(1) {
			if(many-price<0) {
				printf("实收小于应付,请重新输入实收!!!\n");
				printf("实收:");
				scanf("%f",&many);
			} else {
				break;
			}
		}
		printf("找零:%.2f\n",many-price);
		fprintf(fp,"合计:%.2f￥\n",price);
		fprintf(fp,"实收:%.2f￥\n",many);
		fprintf(fp,"找零:%.2f￥\n",many-price);
	} else {
		printf("创建文佳失败!!!\n");
	}
	fclose(fp);
}

int print(shop *head) {    //查看购物车
	shop *p=head->next;
	if(p==NULL) {
		printf("购物车中无货!!!\n");
		return 0 ;
	} else {
		while(p) {
			printf("条形码:%s 商品名称:%s 商品价格:%.2f 商品的数量：%d\n",p->barcode,p->name,p->price,p->count);
			p=p->next;
		}
		return 1;
	}
}

int add(shop *head,int j) {          //添加购物车       //一种商品有一个条形码  价格相同   假设第一次输入的价格为正确价格
	printf("请输入添加商品的种类数/次数:\n");
	int n;
	scanf("%d",&n);
	while(n--) {
		shop *p=head;
		shop *q=(shop*)malloc(LEN);
		printf("请输入商品条形码  商品名称  商品价格  商品数量\n");
		scanf("%s %s %f %d",q->barcode,q->name,&q->price,&q->count);
		int k=1; //      查看是否重复
		for(int i=0; i<j; i++) {   //检索当前链表
			p=p->next;
			if(strcmp(p->barcode,q->barcode)==0  && strcmp(p->name,q->name)==0) {
				if(p->price==q->price) {
					printf("添加成功!!!\n");
					p->count+=q->count;
					k=2;
					free(q);      //节点数目不变 添置以前节点 销毁新节点
					break;
				} else {
					printf("添加失败，商品价格输入错误,该商品价格为:%f，请重新输入!!!\n",p->price);
					k=3;
					n++;
					free(q);     //添加失败 销毁节点
					break;
				}
			} else if(strcmp(p->barcode,q->barcode)==0  || strcmp(p->name,q->name)==0) {
				printf("添加失败,商品或者条形码输入有误,请重新输入!!!\n");
				k=4;
				n++;
				free(q);          //添加失败 销毁节点
				break;
			}
		}
		if(k==1) {
			printf("添加成功!!!\n");
			p->next=q;     //将q节点接到p节点后面
			q->next=NULL;   //使q->next节点指向NULL
			j++;      //节点增加   计数该链表节点数
		}
	}
	return j;
}

void del(shop *head) {         //删除购物车中的数量
	printf("请输入删除商品的种类数/次数:");
	int n;
	scanf("%d",&n);
	while(n--) {
		shop *p=head;
		shop *q=p->next;
		printf("请输入要删除商品的名字及删除数量\n");
		char name[20];
		int count=0;
		scanf("%s %d",name,&count);
		int i=1;
		while(q) {
			if(strcmp(q->name,name)==0) {            //找到商品名称
				if(q->count>count) {
					printf("该商品删除成功!!!\n");
					q->count=q->count-count;    //节点中count的数量减少
					i=1;
					break;
				} else if(q->count<count) {
					printf("该商品删除失败，购物车中商品数量不足!!!\n");
					i=1;
					n++;    //删除次数不变
					break;
				} else {
					printf("该商品删除成功!!!\n");
					p->next=q->next;
					free(q);     //删除节点
					i=1;
					break;
				}
			} else {
				p=p->next;
				q=q->next;        //p q同时后移
				i=0;
			}
		}
		if(i==0) {
			printf("该商品不存在,删除失败!!!\n");
			n++;
		}
	}
}

void change(shop *head) {    //改变购物车商品的数量
	int n;
	printf("请输入改变商品的种类数/次数:");
	scanf("%d",&n);
	while(n--) {
		shop *p;
		p=head->next;
		printf("请输入要改变货物的名称:\n");
		char name[20];
		scanf("%s",name);
		int i=1;
		while(p) {
			if(strcmp(p->name,name)==0) {
				int j=4;
				printf("输入1改变数量 输入2改变价格 输入3改变数量和价格!!!\n");
				char scan[200];
				while(1) {
					scanf("%s",scan);
					if(scan[0]>='0' && scan[1]<='9') {
						if(scan[1]=='\0') {
							break;
						}
					}
					printf("输入指令错误!!!重新输入!!!\n");
				}
				switch (scan[0]) {
					case '1':
						printf("请输入改变后货物的数量:\n");
						scanf("%d",&p->count);
						i=1;
						printf("更改成功!!!\n");
						break;
					case '2':
						printf("请输入改变后商品的价格:\n");
						scanf("%f",&p->price);
						i=1;
						printf("更改成功!!!\n");
						break;
					case '3':
						printf("请输入改变后货物的数量:\n");
						scanf("%d",&p->count);
						printf("请输入改变后商品的价格:\n");
						scanf("%f",&p->price);
						printf("更改成功!!!\n");
						i=1;
						break;
					default:
						printf("输入的指令不正确，请重新输入!!!\n");
						break;
				}
				break;
			} else {
				i=0;
			}
			p=p->next;
		}
		if(i==0) {
			printf("该商品不存在! ! !\n");
			n++;
		}
	}
}

void search(shop *head) {        //搜索购物车中一件商品的数量
	shop *p=head->next;
	if(p==NULL) {
		printf("购物车中无货!!!\n");
		return ;
	}
	int n;
	printf("请输入要搜索商品的次数:\n");
	scanf("%d",&n);
	while(n--) {
		printf("请输入要搜索的商品的名称:\n");
		char name [20];
		scanf("%s",name);
		p=head->next;               //每次都指向head->next
		int i=1;
		while(p) {
			if(strcmp(p->name,name)==0) {
				i=1;
				printf("商品的名称为：%s\n商品价格为:%.2f\n商品数量为:%d\n",name,p->price,p->count);    //进行更改操作
				break;
			} else {
				i=0;
			}
			p=p->next;
		}
		if(i==0) {
			printf("该商品不存在! ! !\n");
			n++;
		}
	}
}

void sort(shop *head) {      //排序
	int temp;
	char temp_[20];
	float _temp;
	shop *q=head->next;
	if(q==NULL) {
		printf("购物车中没有货物!!!\n");
		return ;
	}
	shop *p=head->next;
	shop *cur=head->next;
	shop *tail=head;   //标记尾端指针
	while(tail!=NULL) {
		tail=tail->next;    //tail为尾节点
	}
	int n;
	printf("输入1按价格排序****输入2按数量排序\n");
	char scan[200];
	while(1) {
		scanf("%s",scan);
		if(scan[0]>='0' && scan[1]<='9') {
			if(scan[1]=='\0') {
				break;
			}
		}
		printf("输入指令错误!!!从新输入!!!\n");
	}
	switch(scan[0]) {
		case '1':
			while(p->next!=tail) {
				cur=head->next;
				while(cur->next!=tail) 
				{
					if(cur->price>cur->next->price) {      //交换
						strcpy(temp_,cur->barcode);
						strcpy(cur->barcode,cur->next->barcode);
						strcpy(cur->next->barcode,temp_);      //交换条形码
						strcpy(temp_,cur->name);
						strcpy(cur->name,cur->next->name);      //交换商品名称
						strcpy(cur->next->name,temp_);
						temp=cur->count,
						cur->count=cur->next->count;   //交换商品数量
						cur->next->count=temp;
						_temp=cur->price;
						cur->price=cur->next->price;   //交换商品价格
						cur->next->price=_temp;
					}
					cur=cur->next;
				}
				tail=cur;
			}
			printf("排序成功!!!\n");
			break;
		case '2':
			while(p->next!=tail) {
				cur=head->next;
				while(cur->next!=tail) {
					if(cur->count>cur->next->count) { //交换
						strcpy(temp_,cur->barcode);
						strcpy(cur->barcode,cur->next->barcode);
						strcpy(cur->next->barcode,temp_);
						strcpy(temp_,cur->name);
						strcpy(cur->name,cur->next->name);
						strcpy(cur->next->name,temp_);
						temp=cur->count,
						cur->count=cur->next->count;
						cur->next->count=temp;
						_temp=cur->price;
						cur->price=cur->next->price;
						cur->next->price=_temp;
					}
					cur=cur->next;
				}
				tail=cur;
			}
			printf("排序成功!!!\n");
			break;
		default:
			printf("输入的指令不正确，请重新输入!!!\n");
			break;
	}
}

void ticket() {
	char ticket[100];
	FILE *fp=fopen("小票.txt","r");
	if(fp!=NULL) {
		while(fscanf(fp,"%s",ticket)!=EOF) {
			printf("%s\n",ticket);
		}
	} else {
		printf("打开失败!!!\n");
	}
	fclose(fp);
}

int main() {
	system("color f9");  //设置控制台颜色
	if(lading()) {      //登陆
		shop *head=creat();
		shop *p=head;
		int k,l;
		static int j=0;
		while(1) {
			system("pause");
			system("cls");
			emnu();
			printf("                           请输入数字 以实现对应的功能:\n");
			char scan[200];
			while(1) {
				scanf("%s",scan);
				if(scan[0]>='0' && scan[1]<='9') {
					if(scan[1]=='\0') {
						break;
					}
				}
				printf("输入指令错误!!!从新输入!!!\n");
			}
			switch(scan[0]) {
				case '1':
					k=add( p , j );
					j=k;                      //增加货物
					break;
				case '2':
					l=print(p);
					if(l==1)                  //删除货物
						del(p);
					break;
				case '3':
					search(p);                 //搜索货物
					break;
				case '4':
					l=print(p);
					if(l==1)                   //改变货物
						change(p);
					break;
				case '5':
					sort(p);
					break;
				case '6':
					l=print(p);                //查看购物车
					break;
				case '7':
					check(p);                  //结账
					break;
				case '8':
					ticket() ;                 //打印小票
					break;
				case '9':
					changenp();                //更改密码
					break;
				case '0':
					system("cls");
					byebye();             //再见
					exit(0);              //退出
				default:
					printf("输入的指令不正确，请重新输入!!!\n");
					break;
			}
		}
	}
	system("pause");
	system("cls");
	byebye();
	return 0;
}
