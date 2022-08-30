typedef struct
{
    char key;
    _Bool isWord;
    struct Node *next[26];
    int val;
} MapSum, *Tire;
Tire create_node(char key)
{
    // 创建新节点
    MapSum *newNode;
    newNode = (MapSum *)malloc(sizeof(MapSum));
    newNode->key = key;
    newNode->val = 0;
    newNode->isWord = false;
    for (int i = 0; i < 26; i++)
    {
        newNode->next[i] = NULL;
    }

    return newNode;
}
//添加
void add(char *word, Tire root, int val)
{
    for (int i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        int index = c - 'a';
        if (root->next[index] == NULL)
        {
            root->next[index] = create_node(c);
        }
        root = root->next[index];
    }
    root->val = val;
    if (!root->isWord)
        root->isWord = true;
}
int mapSumRecursion(MapSum *obj)
{
    int ret = obj->val;
    for (int i = 0; i < 26; i++)
    {
        if (obj->next[i])
        {
            ret += mapSumRecursion(obj->next[i]);
        }
    }
    return ret;
}

int isPrefix(char *word, Tire root)
{
    for (int i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        int index = c - 'a';
        root = root->next[index];
        if (root == NULL)
        {
            return 0;
        }
    }
    return mapSumRecursion(root);
}
MapSum *mapSumCreate()
{
    return create_node(0);
}

void mapSumInsert(MapSum *obj, char *key, int val)
{
    add(key, obj, val);
}

int mapSumSum(MapSum *obj, char *prefix)
{
    return isPrefix(prefix, obj);
}

void mapSumFree(MapSum *obj)
{
    for (int i = 0; i < 26; i++)
    {
        if (obj->next[i])
        {
            mapSumFree(obj->next[i]);
        }
    }
    free(obj);
}

/**
 * Your MapSum struct will be instantiated and called as such:
 * MapSum* obj = mapSumCreate();
 * mapSumInsert(obj, key, val);

 * int param_2 = mapSumSum(obj, prefix);

 * mapSumFree(obj);
*/