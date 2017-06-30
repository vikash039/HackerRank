#include <stdio.h>
#include <malloc.h>

#define MAX 23
#define MAXC 26

typedef struct TRIENODE{
	int count;
    struct TRIENODE *child[MAXC];
}trie_n;

int my_strcmp(char *str1, char *str2, int n){
   	int i;
    for(i=0;i<n;i++)
        if(str1[i] != str2[i])
        	return 1;
    return 0;
}

trie_n *getNode(void){
	trie_n *node = (trie_n *)malloc(sizeof(trie_n));
    node->count = 0;
    int i;
    for(i=0;i<MAXC;i++)
        node->child[i] = NULL;
    return node;
}

void insert_trie(trie_n *root, char *str){
	trie_n *crawl = root;
    int idx;
    while(*str){
        idx = *str - 'a';
    	if(crawl->child[idx] == NULL)
            crawl->child[idx] = getNode();
        crawl->child[idx]->count += 1;
        crawl = crawl->child[idx];
        ++str;
    }
}

int search_trie(trie_n *root, char *str){
	trie_n *crawl = root;
    int idx;
    while(*str){
        idx = *str - 'a';
        if(crawl->child[idx] == NULL)
            return 0;
        crawl = crawl->child[idx];
        ++str;
    }
    return crawl->count;
}

int main()
{
    setbuf(stdout, NULL);
	int Q;
    char cmd[5] = {0};
    char str[MAX] = {0};
    scanf("%d", &Q);
    trie_n *root = getNode();
    while(Q--){
        scanf("%s %s", cmd, str);
        if(my_strcmp(cmd, "add", 3) == 0){
        	insert_trie(root, str);
        }else if(my_strcmp(cmd, "find", 4) == 0){
        	printf("%d\n", search_trie(root, str));
        }
    }
    return 0;
}