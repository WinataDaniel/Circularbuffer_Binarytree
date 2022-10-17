# Circularbuffer & Binarytree
Scenario - You start an internship at "Data Fuse Inc.", a leading provider of BigData solutions. In the development department you will support the conception and realization of experimental solutions. <br  />

## 2.1 Backup by means of ring buffer

### 2.1.1 Basic idea
Application example - The creation of backups in an industrial environment is extremely complex and a backup set can quickly comprise several terabytes. However, time-consuming long-term archiving is not always necessary because, for example, the rate of change of the data is too high and therefore too expensive.  Here one uses the trick of the ring backup, with which only a limited number of backup cycles must be kept. If a current backup is created, the oldest backup must be deleted or overwritten. This basic idea can be applied to a variety of problems. problems. <br  />

### 2.1.2 Task
Write a program to create and manage backups using ring buffers. Create a main class Ring, which allows the management of the ring. This class implements all necessary operations on the data structure (e.g. add new elements, output contents, search elements). The actual ring consists of a total of 6 nodes of the class RingNode, which are linked similar to a concatenated list (Fig. 2, 3, 4). An empty ring grows with each added RingNode until it reaches its maximum size of 6. To indicate the age of a data set
each RingNode has the attribute oldAge (most recent: '0', oldest '5'). When the ring reaches its maximum size, a newly added RingNode always replaces the ¨ oldest one - the oldest backup is overwritten. Implement the classes shown in the figure (Fig. 4) (including all attributes and methods) in the provided file template.
<br  /> <br  />
The user should have the following options via the console:
* Enter a new data set. This consists of data of the backup (symbolicData:string) as well as a description (description:string).
* Search for backup data. The console should display the age, description and data text of the backup in question. Otherwise an error message.
* Output all backup information. Ascending list of all backups, format see example

![pic1](https://user-images.githubusercontent.com/115429300/196287789-427c9e9c-4d00-411c-b44e-ff30ee16fb2c.png)
![pic2](https://user-images.githubusercontent.com/115429300/196287851-caa8c097-ee57-4f0f-b5fc-a79da04e6e61.png)

## 2.2 Binary tree - Data management and operation

### 2.1.1 Basic idea
Application example - From the last target group analysis, you are given a large data set that is to be made usable for your analysts. Provide your colleagues with a program that can read, prepare and modify the data set. For the hierarchical organization of the data sets, you have decided to use a binary tree.

### 2.2.1 Task
Develop a main Tree class, which is the parent class (no inheritance meant) that has control over the tree and is responsible for all operations (e.g. add node, delete node, search node, output node, etc.). The actual tree consists of TreeNodes, which have the attributes, functions, as well as the necessary references to the left/right following TreeNode or Nullpointer specified in the illustration (5). The structure to be realized and the functionality of the two classes to be implemented can be seen in Figure 5. You may extend the classes with small auxiliary methods and attributes if it is mandatory for the implementation. Where a TreeNode is placed in the tree is determined by the NodeOrderID attribute. This integer value is calculated from the attributes Age, PostCode and Income of the node.
$\qquad$ $\qquad$ $\qquad$ $\qquad$ ***Age(int) + P ostCode(int) + Income(double) = NodeOrderID(int)*** <br  />
To be able to trace the chronological sequence of operations later, you need an additional serial number (ID) for each TreeNode. To do this, increment the NodeChronologicalID integer attribute of the TreeNode. Note that the NodeChronologicalID is a sequential serial number and should not be confused with the NodeOrderID. Your tree should also be able to find and output nodes based on the Name attribute. Take into account multiple occurrences of names. Furthermore, nodes shall be identified by their NodeOrderID and deleted from the tree. Delete operations must leave the tree in correct state.

The user should have the following options via the console:
* Adding new records as user input
* Importing new records from a CSV file
* Delete an existing record based on the OrderID.
* Searching for a record by the person's name
* Display of the complete tree after preorder.
* Display of the complete tree by level order with level indication.
* End program.

![pic3](https://user-images.githubusercontent.com/115429300/196288127-8cd8766d-4123-432b-a03e-4d87cb3a56df.png)
![pic4](https://user-images.githubusercontent.com/115429300/196288159-858385ca-6131-4b1d-93c2-abd7b354b2a5.png)

Additionally, program a class method levelOrder(void) in the class Tree, which outputs the nodes of the tree in level order.
the nodes of the tree in level order. Since the number of nodes in the tree itself is not
is not stored in the tree itself, it is sufficient to simply output all nodes up to level 10. (If there are no more nodes after a certain level, it can be aborted or nothing can be output).
