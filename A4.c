#include "IoUtilsByBrahvim.h"

typedef unsigned long long ull;

#define OP_ADD '+'
#define OP_SUB '-'
#define OP_DIV '/'
#define OP_MULT '*'

#ifdef _MSC_VER
#pragma pack(push, 1)
#endif

struct binary_expr {
    char op;
    ull n1, n2;
#ifdef __GNUC__
} __attribute__((packed));
#else
};
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif


int main() {

}
