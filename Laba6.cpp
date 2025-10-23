/***************************
 * Автор: Кондратенко Павел*
 * Вариант: 7              *
 ***************************/
 
#include <stdio.h>

int main() {
  struct student {
    char surname[20];
    char name[20];
    char class[10];
    int history;
    int math;
    int physics;
  } s;

  int loopIteration;
  int NumberOfStudents = 0;
  double averageHistory = 0, averageMath = 0, averagePhysics = 0;
  int worstAverage = 100;
  int totalMarks;
  double averageMark;
  char search_class[10];
  char worstSurname[20], worstName[20], worstClass[10];

  FILE *f = fopen("school.txt", "w");
  for (loopIteration = 0; loopIteration < 6; ++loopIteration) {
    printf("Enter student surname: \n");
    scanf("%s", s.surname);
    printf("Enter student name: \n");
    scanf("%s", s.name);
    printf("Enter student class: \n");
    scanf("%s", s.class);
    printf("Enter history mark: \n");
    scanf("%d", &s.history);
    printf("Enter math mark: \n");
    scanf("%d", &s.math);
    printf("Enter physics mark: \n");
    scanf("%d", &s.physics);
    fprintf(f, "%s %s %s %d %d %d\n", s.surname, s.name, s.class, s.history, s.math, s.physics);
    }
    fclose(f);
    
    printf("Enter class to search: \n");
    scanf("%s", search_class);
    f = fopen("school.txt", "r");

  while (fscanf(f, "%s %s %s %d %d %d", s.surname, s.name, s.class, &s.history, &s.math, &s.physics) != EOF) {
     totalMarks = s.history + s.math + s.physics;
     averageMark = totalMarks / 3.0;
        
    if (s.class[0] == search_class[0] && s.class[1] == search_class[1] && s.class[2] == search_class[2]) {
        averageHistory += s.history;
        averageMath += s.math;
        averagePhysics += s.physics;
        NumberOfStudents += 1;
    }
        
    if (averageMark < worstAverage) {
        worstAverage = averageMark;
        int i;
        for (i = 0; s.surname[i] != '\0'; i++) {
            worstSurname[i] = s.surname[i];
            }
            worstSurname[i] = '\0';
            
        for (i = 0; s.name[i] != '\0'; i++) {
            worstName[i] = s.name[i];
            }
        worstName[i] = '\0';
            
        for (i = 0; s.class[i] != '\0'; i++) {
            worstClass[i] = s.class[i];
            }
        worstClass[i] = '\0';
        }
    }
    fclose(f);

  if (NumberOfStudents > 0) {
    averageHistory = averageHistory / NumberOfStudents;
    averageMath = averageMath / NumberOfStudents;
    averagePhysics = averagePhysics / NumberOfStudents;
        
    printf("Average history mark in class %s = %.2f \n", search_class, averageHistory);
    printf("Average math mark in class %s = %.2f \n", search_class, averageMath);
    printf("Average physics mark in class %s = %.2f \n", search_class, averagePhysics);
    printf("Number of students in class %s = %d \n", search_class, NumberOfStudents);
    } else {
    printf("No students found in class: %s \n", search_class);
    }

    printf("Worst student: %s %s (%s), average mark = %d \n", worstSurname, worstName, worstClass, worstAverage);

    return 0;
}
