TestVector : TestVector.C
	g++ TestVector.C -o TestVector

TestOrderedVector : TestOrderedVector.C
	g++ TestOrderedVector.C -o TestOrderedVector

TestSNode : TestSNode.C
	g++ TestSNode.C -o TestSNode

TestSList : TestSList.C
	g++ TestSList.C -o TestSList

TestDNode : TestDNode.C
	g++ TestDNode.C -o TestDNode

TestDList : TestDList.C
	g++ TestDList.C -o TestDList
	
TestList : TestList.C
	g++ TestList.C -o TestList

TestStack : TestStack.C
	g++ TestStack.C -o TestStack

TestQueue : TestQueue.C
	g++ TestQueue.C -o TestQueue
	
TestHeap : TestHeap.C
	g++ TestHeap.C -o TestHeap

TestBinNode : TestBinNode.C
	g++ TestBinNode.C -o TestBinNode
	
TestBSTree : TestBSTree.C
	g++ TestBSTree.C -o TestBSTree

TestTableHash : TestTableHash.C
	g++ TestTableHash.C -o TestTableHash

TestAVLTree : TestAVLTree.C
	g++ TestAVLTree.C -o TestAVLTree
	
TestBinHeap: TestBinHeap.C
	g++ TestBinHeap.C -o TestBinHeap
	
all : 
	g++ TestVector.C -o TestVector
	g++ TestOrderedVector.C -o TestOrderedVector
	g++ TestSNode.C -o TestSNode
	g++ TestSList.C -o TestSList
	g++ TestDNode.C -o TestDNode
	g++ TestDList.C -o TestDList
	g++ TestList.C -o TestList
	g++ TestStack.C -o TestStack
	g++ TestQueue.C -o TestQueue
	g++ TestHeap.C -o TestHeap
	g++ TestBinNode.C -o TestBinNode
	g++ TestBSTree.C -o TestBSTree
	g++ TestTableHash.C -o TestTableHash
	g++ TestAVLTree.C -o TestAVLTree
	g++ TestBinHeap.C -o TestBinHeap
	
clean :
	rm TestVector TestOrderedVector TestSNode TestSList TestDNode TestDList TestStack TestQueue TestHeap 
	rm TestList TestBinNode TestBSTree TestTableHash TestAVLTree TestBinHeap
