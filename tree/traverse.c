#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagNode {
    struct tagNode* left;
    struct tagNode* right;
    ElementType data;
} Node;


/* 노드 생성 */
Node* CreateNode(ElementType newData)
{
    // 노드를 위한 메모리 할당
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;

    return newNode;
}

/* 노드 파괴 */
void DestroyNode(Node* node)
{
    free(node);
}

/* 트리 파괴(후위 순회 활용) */
void DestroyTree(Node* root)
{
    if(root == NULL)
        return;

    // 왼쪽 하위 트리 소멸
    DestroyTree(root->left);

    // 오른쪽 하위 트리 소멸
    DestroyTree(root->right);

    // 루트 노드 소멸
    DestroyNode(root);
}

/* 전위 순회 */
void PreOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;

    // 부모 노드 출력
    printf(" %c", node->data);

    // 왼쪽 하위 트리 출력
    PreOrderPrintTree(node->left);

    // 오른쪽 하위 트리 출력
    PreOrderPrintTree(node->right);
}

/* 중위 순회 */
void InOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;

    // 왼쪽 하위 트리 출력
    InOrderPrintTree(node->left);

    // 부모 노드 출력
    printf(" %c", node->data);

    // 오른쪽 하위 트리 출력
    InOrderPrintTree(node->right);
}

/* 후위 순회 */
void PostOrderPrintTree(Node* node)
{
    if(node == NULL)
        return;

    // 왼쪽 하위 트리 출력
    PostOrderPrintTree(node->left);

    // 오른쪽 하위 트리 출력
    PostOrderPrintTree(node->right);

    // 부모 노드 출력
    printf(" %c", node->data);
}

int main()
{
    // 노드 생성
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');
    Node* F = CreateNode('F');
    Node* G = CreateNode('G');

    /*
     *       A
     *     /   \
     *    B     E
     *   / \   / \
     *  C   D F   G
     */

    // 트리에 노드 추가
    A->left = B;
    B->left = C;
    B->right = D;

    A->right = E;
    E->left = F;
    E->right = G;

    // 트리 출력
    printf("PreOrder...\n");
    PreOrderPrintTree(A);
    printf("\n\n");

    printf("InOrder...\n");
    InOrderPrintTree(A);
    printf("\n\n");

    printf("PostOrder...\n");
    PostOrderPrintTree(A);
    printf("\n");

    // 소멸
    DestroyTree(A);

    return 0;
}
