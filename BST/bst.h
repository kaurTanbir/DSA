typedef int Compare(void* first, void* second);

typedef struct{
    void* root;
    Compare* comparator;
}BST;

typedef struct {
    void* left;
    void* right;
}Child_data;

void* getRootData(BST tree);
BST createTree(Compare* comp);
int insertInTree(BST* tree, void* dataToInsert);
Child_data getChildData(BST tree,void* parentData);