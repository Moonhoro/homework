struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *pre, *post;
    post = head;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    pre = dummy;
    for (int i = 0; i < n; i++)
    {
        post = post->next;
    }
    while (post)
    {
        post = post->next;
        pre = pre->next;
    }

    pre->next = pre->next->next;
    return dummy->next;
}