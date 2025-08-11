#pragma once

namespace Non_Linear_Data_Structures
{
	/// <summary>
	/// struct Node
	/// <param name="data">T</param>
	/// <param name="childCount">int</param>
	/// <param name="capacity">int</param>
	/// <param name="parent">Node*</param>
	/// <param name="children">Node**</param>
	/// </summary>
	template <typename T>
	struct Node
	{
		T data;
		int childCount;
		int capacity;

		Node<T>* parent;
		Node<T>** children;
	};
}