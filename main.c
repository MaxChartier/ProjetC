//
// Created by Max Chartier on 29/03/2023.
//
#include <stdio.h>
#include <malloc.h>


typedef struct {
    int pos_x;
    int pos_y;
}Point;

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Point *create_point(int px, int py) {
    Point *p = malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

Line *create_line(Point * p1, Point * p2) {
    Line *line = malloc(sizeof(Line));
    line->p1 = create_point(p1->pos_x, p1->pos_y);
    line->p2 = create_point(p2->pos_x, p2->pos_y);
    return line;
}
void delete_line(Line * line){
    free(line);}

void delete_point(Point * point){
    free(point);
}
void print_line(Line * line){
    printf("LINE [%d,%d,%d,%d]",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}


void print_point(Point * p){
    printf("POINT[p(%d,%d)]",p->pos_x,p->pos_y);
}




int main() {
    char choice;
    int choice2;
    printf("Please select an action:\n"
           "A- Add a shape\n"
           "B- Display the list of shapes\n"
           "C- Delete a shape\n"
           "D- Drawing the shapes\n"
           "E- Help\n");
    scanf("%c",&choice);
    if (choice=='A'){
        printf("Please select an action:\n"
               "1- Add a point\n"
               "2- Add a line\n"
               "3- Add circle\n"
               "4- Add a square\n"
               "5- Add a rectangle\n"
               "6- Add a polygon\n"
               "7- Return to previous menu\n");
        scanf("%d",&choice2);
        if (choice2==1){
            int x,y;
            printf("Give the coordinates in the form x y");
            scanf("%d %d",&x,&y);
            Point *Point1 = create_point(x,y);
            print_point(Point1);
        }
        if (choice2==2){
            int x1, y1, x2, y2;

            printf("Enter the x and y coordinates for the start point:\n");
            scanf("%d %d", &x1, &y1);
            Point *p1 = create_point(x1, y1);

            printf("Enter the x and y coordinates for the end point:\n");
            scanf("%d %d", &x2, &y2);
            Point *p2 = create_point(x2, y2);

            Line *line = create_line(p1, p2);
            print_line(line);

        }

    }
    return 0;
}

