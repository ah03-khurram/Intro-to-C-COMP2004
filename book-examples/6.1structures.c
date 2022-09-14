/* 
    Examples on C struct
*/

#include <stdio.h>

struct coord {
    int x;
    int y;
};

struct rect {
    struct coord pt1;
    struct coord coord2;
};

typedef struct {
    int x;
    int y;
} mycoord;

int print_coord(struct coord coord1);
int print_mypoint(mycoord coord1);
int coord_inc(struct coord *coord1);

int main(){
    struct coord coord1;
    struct coord *p_coord1;
    
    coord1.x = 10;
    coord1.y = 20;

    print_coord(coord1);

    p_coord1 = &coord1; // pointer to my coord
    printf("Pointer to coord1 (%d, %d)\n", (*p_coord1).x, (*p_coord1).y); // (*p_coord1) is the object so you can access using dot "." same with coord1 
    printf("Pointer to coord1 (%d, %d)\n", p_coord1->x, p_coord1->y);
    
    // Change the original point
    coord_inc(p_coord1);
    print_coord(coord1);

    mycoord coord2; // typedef
        
    coord2.x = 30;
    coord2.y = 40;

    print_mypoint(coord2); // different function parameter

    struct rect rec1;

    rec1.pt1.x = 0;
    rec1.pt1.y = 0;
    rec1.coord2.x = 1;
    rec1.coord2.y = 1;

    printf("My rec (%d, %d, %d, %d)\n", rec1.pt1.x, rec1.pt1.y, rec1.coord2.x, rec1.coord2.y);
    
}

int print_coord(struct coord coord1) {
    printf("%d, %d\n", coord1.x, coord1.y);
}

int coord_inc(struct coord *coord1) {
    coord1->x += 1;
    coord1->y += 1;
}

int print_mypoint(mycoord coord1) {
    printf("%d, %d\n", coord1.x, coord1.y);
}