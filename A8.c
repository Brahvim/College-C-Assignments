// Author: Brahvim Bhaktvatsal

#pragma region // Header declarations.
#include "include/IoUtilsByBrahvim.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long ull;

#define NUM_SUBJECTS (ull)6
#define MAX_NAME_LEN (ull)80

DECLARE_GENERIC_INPUT_FUNCTIONS(ull);
DECLARE_GENERIC_INPUT_FUNCTIONS(float);

// "Keep it simple, stupid!":
// PS These declarations follow the Linux kernel's naming convention (no `typedef`).
struct student;
#pragma endregion

DEFINE_GENERIC_INPUT_FUNCTIONS(ull, "%llu");// Structures (following the convention for the Linux kernel - without `typedef`s):struct student;
DEFINE_GENERIC_INPUT_FUNCTIONS(float, "%f");// Structures (following the convention for the Linux kernel - without `typedef`s):struct student;

struct student {
    ull regno;
    float total;
    char name[MAX_NAME_LEN];
    float marks[NUM_SUBJECTS];
} /* __attribute__((packed)) */;

int main() {
    puts("Welcome to the marksheet-generation program!");
    ull num_students = ensure_user_inputs_ull("number of students");

    struct student *students_array = (struct student *)calloc(num_students, sizeof(struct student));

    if (students_array == NULL) {
        fputs("Heap allocation error.", stderr);
        exit(EXIT_FAILURE);
    }

    for (ull i = 1; i <= num_students; i++) {
        struct student *current_student = students_array + i * sizeof(struct student);

        puts("For student `%llu`:");
        printf("Please enter the name (length below `%llu`, in ASCII): ", MAX_NAME_LEN);

        for (ull name_len = 0; name_len < MAX_NAME_LEN; name_len++) {
            char c = getchar();
            if (c == '\n' || c == EOF) {
                current_student->name[name_len] = '\0';
                break;
            }
            current_student->name[name_len] = c;
        }

        clear_stdin();
        current_student->regno = ensure_user_inputs_ull("registration number");

        printf("Please enter marks for all `%llu` subjects:\n", NUM_SUBJECTS);

        for (ull j = 0; j < NUM_SUBJECTS; j++) {
            const float marks = current_student->marks[j] = ensure_user_inputs_float("marks for this subject");
            current_student->total += marks;
        }

    }

    puts("Total for all students:");

    for (ull i = 0; i < num_students; i++) {
        struct student current_student = students_array[i];
        printf("Total for %s: `%f`.\n", current_student.name, current_student.total);
    }


    // Only one free at the end. Nowhere else.
    free(students_array);

}
