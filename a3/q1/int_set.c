#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int* element;
    int size;
    int capacity;
} Set;

void Set_init(Set* set, int init_capacity){
    set->element = malloc(init_capacity * sizeof(int));
    set->size = 0;
    set->capacity = init_capacity;
}

void free_set(Set* set){
    free(set->element);
}

int binary_search(Set* set, int num){
    int left = 0, right = (set->size) - 1;

    while (left <= right){
        int mid = left - (left - right) / 2;

        if(set -> element[mid] == num) return mid;

        else if(set -> element[mid] < num) left = mid + 1;

        else right = mid - 1;
    }

    return -1;
}

void resize_set(Set* set){
    set -> capacity *= 2;
    set -> element = (int*)realloc(set -> element, (set -> capacity) * sizeof(int)); 
}



void add_num(Set* set, int num){
    int index = binary_search(set, num);

    if(index != -1) return;

    if(set -> size == set -> capacity)
        resize_set(set);

    int i;

    for(i = (set -> size) - 1; (i >= 0 && set -> element[i] > num); --i)
        set -> element[i + 1] = set -> element[i];

    set -> element[i + 1] = num;
    set -> size++;
}

void remove_num(Set* set, int num){
    int index = binary_search(set, num);

    if(index == -1) return;

    for(int i = index; i <= (set -> size) - 1; ++i)
        set -> element[i] = set -> element[i + 1];

    set -> size--;
}

void print_set(Set* set){
    for(int i = 0; i < set -> size; ++i)
        printf("%d ", set -> element[i]);

    printf("\n");
}

void union_sets(Set* set1, Set* set2, Set* result){
    int i = 0, j = 0;
    result -> size = 0;

    while(i < set1 -> size && j < set2 -> size){
        if(set1 -> element[i] < set2 -> element[j])
            add_num(result, set1 -> element[i++]);

        else if(set2 -> element[j] < set1 -> element[i])
            add_num(result, set2 -> element[j++]);

        else{
            add_num(result, set1 -> element[i++]);
            j++;
        }
    }

    while(i < set1 -> size)
        add_num(result, set1 -> element[i++]);

    while(j < set2 -> size)
        add_num(result, set2 -> element[j++]);
}

void intersection_sets(Set* set1, Set* set2, Set* result){
    int i = 0, j = 0;
    result -> size = 0;

    while(i < set1 -> size && j < set2 -> size){
        if(set1 -> element[i] < set2 -> element[j]) i++;

        else if(set2 -> element[j] < set1 -> element[i]) j++;

        else{
            add_num(result, set1 -> element[i++]);
            j++;
        }
    }
}

int main(){
    Set set_x, set_y, result;

    Set_init(&set_x, 1);
    Set_init(&set_y, 1);
    Set_init(&result, 1);

    char op[1], targ[1];
    int num;

    while(1){
        scanf("%s", op);

        if(strcmp(op, "q") == 0) break;

        else if(strcmp(op, "a") == 0){
            scanf("%s %d", targ, &num);

            if(strcmp(targ, "x") == 0)
                add_num(&set_x, num);

            else if(strcmp(targ, "y") == 0)
                add_num(&set_y, num);
        }

        else if(strcmp(op, "r") == 0){
            scanf("%s %d", targ, &num);

            if(strcmp(targ, "x") == 0)
                remove_num(&set_x, num);

            else if(strcmp(targ, "y") == 0)
                remove_num(&set_y, num);
        }

        else if(strcmp(op, "p") == 0){
            scanf("%s", targ);

            if(strcmp(targ, "x") == 0)
                print_set(&set_x);

            else if(strcmp(targ, "y") == 0)
                print_set(&set_y);
        }

        else if(strcmp(op, "u") == 0){
            union_sets(&set_x, &set_y, &result);
            print_set(&result);
        }

        else if(strcmp(op, "i") == 0){
            intersection_sets(&set_x, &set_y, &result);
            print_set(&result);
        }
    }

    free_set(&set_x);
    free_set(&set_y);
    free_set(&result);

    return 0;
}