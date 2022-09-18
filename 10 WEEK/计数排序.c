#include<stdlib.h>
#define R 101
typedef struct Student{
    String name;
    int score;
}*Student;
void sort (Student student,int len) {
    int *cnt = malloc(sizeof(int) * R);
    for (int i = 0; i < len;i++) {
        cnt[student->score]++
    }
    int *index= malloc(sizeof (int)*(R+1));
    for(int j=0;j<R;j++){
index[j+1]=index[j]+cnt[i];
    }
    Student temp= malloc(sizeof (struct student)*len);
    for(int k=0;k<len;k++){
        temp[index[student->score]]=student;
        index[student->score]++;
    }
    for(int i=0;i<len;i++){
        student[i]=temp[i];
    }
}