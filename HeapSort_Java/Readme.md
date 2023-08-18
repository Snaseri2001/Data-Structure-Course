## Heap Sort Java
The code of the problem cen be found [Here.]([https://github.com/Snaseri2001/Data-Structure-Course/blob/main/HeapSort_Cpp/src/HeapSort.h](https://github.com/Snaseri2001/Data-Structure-Course/blob/main/HeapSort_Java/src/ac/um/ds/HeapSort/HeapSort.java))
In this exercise, we have to write the functions below which are located in Heap.h file: <br>
<br>![Screenshot from 2023-08-19 00-59-13](https://github.com/Snaseri2001/Data-Structure-Course/assets/60386309/5d709250-0191-42cd-91bb-e9b9e8671b6b)

and also the body of the sort function has to be performed :<br> 

![Screenshot from 2023-08-19 00-59-43](https://github.com/Snaseri2001/Data-Structure-Course/assets/60386309/529fdd1f-94c3-4a4a-9cd9-068c851ca43a)

<br>
initialized function is gotten 2 parameters :
1.data: The array corresponds to the heap tree. Note that this tree A tree is complete, in this sense If we number the nodes, the number of each node corresponds to the number of the same node A full tree of equal depth As a result, if the numbering starts from 1, the left child of node i The m is the i*2nd node and the right child of the i*2+1st node. Also, in this tree, it is not possible for the true child to exist that there is no left child.
<br>
2.n: the size of the tree ornubmber of the leaves.
<br>
In this function, we are going to change the tree (array) in such a way that it becomes A tree should be Heap Max, in other words, each node should be the largest node in its subtree.<br>


In the deleteMax function, the largest node of the tree, which is the root, should be deleted. After deleting the root, we need to maintain the Max Heap property. We can achieve this by replacing the deleted root with the last node of the tree and then move it to its correct position (if necessary).
<br>
In the insert function, a new node is placed at the end of the tree (after the last node). It is then compared with its parent node and moved repeatedly until it is in its correct position. This function takes a parameter which represents the new data to be inserted.
<br>
The function of sort in HeapSort gets 2 params :<br>
1.data : an array which is related to Max Heap . <br>
2.n : size of the given Max Heap .<br>
This function converts the array corresponding to Heap Max into an ascending array.


