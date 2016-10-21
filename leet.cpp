#include"leet.h"
void leet::myCombinations(string digits, vector<string >&dst, string temp, map<char, string> table) {
	int curlen = temp.size();
	if (curlen == digits.length()) {
		dst.push_back(temp);
	}
	else
	{
		for (int i = 0; i < table[digits[curlen]].size(); i++) {
			temp.push_back(table[digits[curlen]][i]);
			myCombinations(digits, dst, temp, table);
			temp.pop_back();
		}
	}
}
vector<string> leet::letterCombinations(string digits) {
	map<char, string> table = {
		{ '2',"abc" },
		{ '3',"def" },
		{ '4',"ghi" },
		{ '5',"jkl" },
		{ '6',"mno" },
		{ '7',"pqrs" },
		{ '8',"tuv" },
		{ '9',"wxyz" }
	};
	string temp = "";
	vector<string > dst;
	if (digits.size() < 1) return dst;
	myCombinations(digits, dst, temp, table);
	return dst;
}
vector<vector<int>> leet::fourSum(vector<int>& nums, int target) {
	int len = nums.size();
	vector<vector<int>> ans;
	if (len < 4) return ans;
	sort(nums.begin(),nums.end());
	for (int i = 0; i < len - 3; i++) {
		while (i > 0 && nums[i] == nums[i - 1] && i < len - 3) { i++; }
		for (int j = i+1; j < len - 2; j++)
		{
			while (j > i+1 && nums[j] == nums[j - 1] && i < len - 2) { j++; }
			int begin = j + 1;
			int end = len - 1;
			while (begin < end) {
				int sum = nums[i] + nums[j] + nums[begin] + nums[end];
				if (sum == target) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[begin]);
					temp.push_back(nums[end]);
					ans.push_back(temp);
					begin++;
					end--;
					while (nums[begin] == nums[begin-1]) { begin++; }
					while (nums[end] == nums[end + 1]) { end--; }
				}
				else if (sum < target) {
					begin = begin + 1;
				}
				else
				{
					end = end - 1;
				}
			}
		}
	}
	return ans;
}
ListNode* leet::removeNthFromEnd(ListNode* head, int n) {
	int len = 0;
	ListNode* p = head;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	if (len < n) return head;
	if (len == n) { 
		ListNode*q = head;
		head = head->next;
		free(q);
		return head;
	}
	int deleNode = len - n;
	p = head;
	while (deleNode > 1) {
		p = p->next;
		deleNode--;
	}
	ListNode*q = p->next;
	p->next = q->next;
	free(q);
	return head;
}
bool leet::isValid(string s) {
	stack<char> stac;
	int i = 0;
	while (s[i] != NULL)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			stac.push(s[i]);
		}
		else if (!stac.empty() && s[i] == ')')
		{
			char ch = stac.top();
			if (ch != '(') return false;
			stac.pop();
		}
		else if (!stac.empty() && s[i] == '}')
		{
			char ch = stac.top();
			if (ch != '{') return false;
			stac.pop();
		}
		else if (!stac.empty() && s[i] == ']')
		{
			char ch = stac.top();
			if (ch != '[') return false;
			stac.pop();
		}
		else return false;
		i++;
	}
	return stac.empty() ? true : false;
}
ListNode* leet::mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode* ans = (ListNode*)malloc(sizeof(ListNode));
	ListNode* head = ans;
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) { ans->next = l2; break; }
		if (l2 == NULL) { ans->next = l1; break; }
		if (l1->val <= l2->val) {
			ans->next = l1;
			l1 = l1->next;
			ans = ans->next;
		}
		else {
			ans->next = l2;
			l2 = l2->next;
			ans = ans->next;
		}
	}
	return head->next;
}
vector<string> leet::generateParenthesis(int n) {
	vector<string> ans;
	myGenerateParenthesis(ans,"", n, n);
	return ans;
}
void leet::myGenerateParenthesis(vector<string> &dst, string temp, int left, int right) {
	if (right == 0 && left == 0) {
		dst.push_back(temp);
	}
	else {
		if (left > 0) {
			myGenerateParenthesis(dst, temp+'(', left - 1, right);
		}
		if (right > 0 && left<right) {
			myGenerateParenthesis(dst, temp+')', left, right - 1);
		}
	}
}
ListNode* leet::swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL) { return head; }
	ListNode* ans = head->next;
	while (head != NULL && head->next != NULL) {
		ListNode* p,*q;
		p = head;
		q = head->next;
		head = q->next;
		if (q->next == NULL||q->next->next==NULL) {
			if (q->next == NULL)
				p->next = NULL;
			else
				p->next = q->next;
		}
		else
		p->next = q->next->next;
		q->next = p;
		
	}
	return ans;
}
