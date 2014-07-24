#ifndef CustomAssert_H
#define CustomAssert_H

#define TEST_ASSERT_EQUAL_AVL_Node(expectedLeft,expectedRight,balance,actual)	\
					assertAvlNode(expectedLeft,expectedRight,balance,actual,__LINE__)

#endif // CustomAssert_H