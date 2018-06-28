#include<stdio.h>
#include<string.h>
int main(void)
{
    typedef struct {
      int id;
      char name[20];
      int age;
      char sex;
      double score;
    }student;//结构体大小37字节
    student s1,s2;
    student *p;
    p = &s1;
    //s1.id = 1;
    //s1.age = 20;
    //strcpy(s1.name,"张三");
    //(*p).id = 1;
    //(*p).age = 20;
    //strcpy((*p).name,"张三");
    p->id = 1;
    p->age = 20;
    strcpy(p->name,"张三");
    printf("id = %d,name = %s,age = %d\n",
            s1.id,s1.name,s1.age);
    printf("size = %d\n",sizeof(student));
    return 0;
}
