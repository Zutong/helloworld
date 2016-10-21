#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<limits>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class leet
{
public:
	vector<string> letterCombinations(string digits);  
	vector<vector<int>> fourSum(vector<int>& nums, int target);//leetcode 18
	ListNode* removeNthFromEnd(ListNode* head, int n); // leetcode 19
	bool isValid(string s);                            //leet 20
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);  //leet 21
	vector<string> generateParenthesis(int n);     //leet 22
	ListNode* swapPairs(ListNode* head);            //leet 24

private:
	void myCombinations(string digits, vector<string >&dst, string temp, map<char, string> table);
	void myGenerateParenthesis(vector<string>&dst, string temp, int right, int left); //leet22
};
