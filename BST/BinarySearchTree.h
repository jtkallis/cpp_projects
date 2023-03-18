/******************************
Project 3 Random Binary Search Tree
BinarySearchTree.h  
John Kallis <jkallis1@umbc.edu>
CMSC 341 - 02
Lupoli
3/8/2015

Some of this code was provided by Mr. Lupoli and downloaded from blackboard
I also used code from the following sites
http://www.sanfoundry.com/cpp-program-implement-randomized-binary-search-tree/
http://kukuruku.co/hub/cpp/randomized-binary-search-trees
http://www.sourcetricks.com/2011/05/c-pre-order-in-order-post-order.html#.VQkkCI7F_2A
******************************/


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "dsexceptions.h"


#include <iostream>    // For NULL
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
// used these for help
//http://www.sanfoundry.com/cpp-program-implement-randomized-binary-search-tree/
//http://kukuruku.co/hub/cpp/randomized-binary-search-trees
//http://www.sourcetricks.com/2011/05/c-pre-order-in-order-post-order.html#.VQkkCI7F_2A
//http://stackoverflow.com/questions/19967134/bst-find-height-recursivly
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted


class BinarySearchTree
{
public:
    /**********************
    //Name: BinarySearchTree ( defualt constructor)
    //Preconditions: None
    //Postconditins: Sets root to NULL
    **********************/
    BinarySearchTree( ) :root( NULL )
    {
    }
    /**********************
    //Name: BinarySearchTree (constructor)
    //Preconditions: A BST
    //Postconditins: sets root to NULL and *this=rhs
    **********************/
    BinarySearchTree( const BinarySearchTree & rhs ) : root( NULL )
    {
        *this = rhs;
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const int findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    int findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        return findMax( root )->element;
    }

    /**
     * Bootstrap function. 
     * Returns true if x is found in the tree.
     */
    bool contains( int x ) const
    {
        return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ostream & out = cout ) const
    {
        if( isEmpty( ) )
            out << "Empty tree" << endl;
        else
            printTree( root, out );
    }
    /**********************
    //Name: printLevelOrder (bootstrap)
    //Preconditions: the height of the current tree and the out stream ( optional )
    //Postconditins: calls the printLevelOrder function
    **********************/
    void printLevelOrder( int height, ostream & out ) const
    {
        if (isEmpty( ) )
            out << " empty tree" << endl;
        else
            printLevelOrder( height, root, out );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    /**********************
    //Name: height (bootstrap)
    //Preconditions: None
    //Postconditins: calls the height function
    **********************/
    int height() { return height( root ); }
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( int x ) { insert( x, root ); }

    /**********************
    //Name: randomInsert ( bootstrap )
    //Preconditions: the value to insert
    //Postconditins: calls the randomInsert Function
    **********************/
    void randomInsert ( int x ) { randomInsert( x, root ); }

    /**********************
    //Name: insertAtRoot (bootstrap)
    //Preconditions: the value to insert
    //Postconditins: calls the insertAtRoot function
    **********************/
    void insertAtRoot( int x ) { root = insertAtRoot( x, root ); }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */

    void remove( int x )
    {
        remove( x, root );
    }

    /**
     * Deep copy.
     */
    const BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }


private:  // this private BinaryNode is within BST


    struct BinaryNode
    {
        int element;
        int roots;
        BinaryNode *left;
        BinaryNode *right;
        /**********************
        //Name: BinaryNode ( defualt constructor)
        //Preconditions: A Tree must exist to enter a node into
        //Postconditins: sets the properties of the node
         **********************/
        BinaryNode( int theElement, int TheRoots, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), roots( TheRoots ), left( lt ), right( rt ) { }

    };

    BinaryNode *root;



    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( int x, BinaryNode * & t )
    {
		if( t == NULL ) { t = new BinaryNode( x, 1, NULL, NULL ); } // no node present yet
        else if( x < t->element ) 
        { 
            t->roots++;
            insert( x, t->left );// value in CURRENT root 't' < new value
        } 
		else if( t->element < x ) 
        { 
            t->roots++;
            insert( x, t->right );
        }
        else;  // Duplicate; do nothing
    }
    /**********************
    //Name: getsize
    //Preconditions: None
    //Postconditins: returns the number of roots
    **********************/
    int getsize( BinaryNode * t)
    {
        if ( !t ) { return 0; }
        return t->roots;
    }
    /**********************
    //Name: fixsize
    //Preconditions: None
    //Postconditins: sets the correct roots for tree
    **********************/
    void fixsize( BinaryNode * t )
    {
        t->roots = getsize(t->left)+getsize(t->right)+1;
    }

    /**********************
    //Name: randomInsert
    //Preconditions: None
    //Postconditins: inserts a Node into a Tree at random root
    **********************/
    void randomInsert( int x, BinaryNode * & t )
    {
        
        if ( t == NULL ) { t = new BinaryNode( x, 1, NULL, NULL ); }
        else
        {
            
            int r = rand( ) % t->roots + 1;
             if ( r == t->roots )
            {   
                t = insertAtRoot( x, t );
            }
            else
            {
                if ( x < t->element )
                {
                    t->roots++;
                    randomInsert( x, t->left );
                }
                else
                {
                    t->roots++;
                    randomInsert( x, t->right );
                }

            }
        }
    }
    /**********************
    //Name: insertAtRoot
    //Preconditions: a Tree is already constructed
    //Postconditins: inserts a Node at the current root by rotating about the root. returns a BinaryNode
    **********************/   
    BinaryNode * insertAtRoot( int x, BinaryNode * & t )
    {
        if ( t == NULL )
        {
            return new BinaryNode( x, 1, NULL, NULL );
        }

        else if ( x < t->element )
        {
            t->left = insertAtRoot( x, t->left );
            BinaryNode * nt = t->left;
            if ( !nt ) { return t;}
            t->left = nt->right;
            nt->right = t;
            nt->roots = t->roots;
            fixsize(nt);
            return nt;
            
        }
        else if ( x > t->element )
        {
            t->right = insertAtRoot(x, t->right );
            BinaryNode * nt = t->right;
            if( !nt ) { return nt; }
            t->right = nt->left;
            nt->left = t;
            nt->roots = t->roots;
            fixsize(nt);
            return nt;
        }
        return t;
    }
    /**********************
    //Name: height
    //Preconditions: None
    //Postconditins: returns the height of a tree from current node
    **********************/
    int height( BinaryNode *t )
    {
        if( t == NULL) { return -1; }

        int leftHeight = height(t->left);
        int rightHeight = height(t->right);

        if ( leftHeight > rightHeight ) { return leftHeight +1;}
        else { return rightHeight + 1;}
    }



    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( int x, BinaryNode * & t )
    {
        if( t == NULL )
        {
            return;   // Item not found; do nothing
        }
        if( x < t->element )
        {
            remove( x, t->left );
        }
        else if( t->element < x )
        {
            remove( x, t->right );
        }
        else if( t->left != NULL && t->right != NULL ) // Two children
        {
            t->element = findMax( t->left )->element;
            remove( t->element, t->left );
        }
        else
        {
            BinaryNode *oldNode = t;
            t = ( t->left != NULL ) ? t->left : t->right;
            delete oldNode;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode * findMax( BinaryNode *t ) const
    {
        if ( t == NULL )
            return NULL;
        if ( t->right == NULL )
            return t;
        return findMax( t->right );
    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
    bool contains( int x, BinaryNode *t ) const
    {
        if( t == NULL )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    /****** NONRECURSIVE VERSION*************************
        bool contains( const Comparable & x, BinaryNode *t ) const
        {
            while( t != NULL )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return true;    // Match

            return false;   // No match
        }
    *****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

    /**********************
    //Name: printTree
    //Preconditions: None
    //Postconditins: prints the tree in preOrder
    **********************/
    void printTree( BinaryNode *t, ostream & out ) const
    {       

        out << t->element << "/" << t->roots << endl;
        
        if ( t != NULL )
        {
            if ( t->left != NULL ) { printTree( t->left, out ); }
            if ( t->right != NULL ) { printTree( t->right, out ); }
        }

        return;
    }
    /**********************
    //Name: printLevelOrder
    //Preconditions: height of the tree must be known
    //Postconditins: creates an ostream of Node elements in level order
    **********************/
    void printLevelOrder( int height, BinaryNode *t, ostream & out ) const
    {
        queue<BinaryNode*> levelOrder;
        levelOrder.push(t);
        int currentLevel = 1;
        int nextLevel = 0;
        int level = 1;
       
        out << endl;
        out << "level 0: ";
        while ( !levelOrder.empty( ) )
        {
            BinaryNode* temp = levelOrder.front( );
            levelOrder.pop( );
            currentLevel--;
            out << temp->element << " ";

            if ( temp->left )
            {
                levelOrder.push( temp->left );
                nextLevel++;
            }
            if ( temp->right )
            {
                levelOrder.push(temp->right );
                nextLevel++;
            }
            if ( currentLevel == 0 )
            {
                if ( level == height )
                {
                    out<<endl;
                    out << "level "<<level<<": ";
                }
                else
                {
                    out<<endl;
                    out << "level "<< level <<": ";
                    currentLevel = nextLevel;
                    nextLevel = 0;
                    level++;
                }       
            }
        
        }//close while t loop
        out<<endl;

    }
    /**
     * Internal method to clone subtree.
     */
    BinaryNode * clone( BinaryNode *t ) const
    {
        if( t == NULL )
            return NULL;
        else
            return new BinaryNode( t->element, t->roots, clone( t->left ), clone( t->right ) );
    }
};

#endif
