  
int findKthLargest(vector<int>& nums, int k) {
  priority_queue<int> pq;
  int top = 0;
  for (auto i : nums)
    pq.push(i);

  while (k > 0) {
    top = pq.top();
    pq.pop();
    k--;
  }
  return top;
}