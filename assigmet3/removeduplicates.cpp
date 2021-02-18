public void removeAllDuplicates()
{
	Node curr = head;
	int prevVal = 0;
	Node prev = null;
	while (curr != null)
	{
		Node nxt = curr.next;
		if ((prevVal == curr.val) || ((nxt != null) && (nxt.val == curr.val)))
		{
			prevVal = curr.val;
			if (prev == null)
			{
				head = nxt;
			}
			else
			{
				prev.next = nxt;
			}
			curr = null;
		}
		if (curr != null)
			prev = curr;
		curr = nxt;
	}

}