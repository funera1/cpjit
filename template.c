// https://github.com/tamaroning/cpcpp/blob/main/stencil/src/template.cc
#define IMPL_I32_CONST impl_i32_const()
#define IMPL_I32_ADD   impl_i32_add()

typedef struct {
    // とりあえずスタックサイズ固定
    int stack[100];
    int stack_pointer;
} ExecCtx;

#define PUSH(value) do {                    \
    ExecCtx.stack[stack_pointer] = value;   \
    stack_pointer++;                        \
} while(0)

// 命令の引数はどう扱う?
void impl_i32_const(ExecCtx ctx) {
    // oparg = 0;
    PUSH(1);
}

#define CONCAT(a, b) a##b
#define IMPL(OP_NAME) CONCAT(IMPL_, OP_NAME)

int
_JIT_ENTRY() {
    IMPL(_JIT_OPCODE);
}