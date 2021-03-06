/**
 * @author Daniel Sebastian Iliescu
 * @file node.cp *
 * This file contains the implementation for Node struct,
 * that is the node definition in the TBST.
 */

#include "node.hpp"

#include <iostream>

namespace dsa
{
    /**
     * Node(const string& token)
     *
     * Default constructor
     */
    Node::Node()
        : id(0),
        depth(0),
        parentNode(nullptr),
        leftNode(nullptr),
        rightNode(nullptr),
        leftNodeType(THREAD),
        rightNodeType(THREAD)
    {
    }

    /**
     * Node(const StackNode& source)
     *
     * Copy constructor
     * @param source Node to copy
     */
    Node::Node(const Node& source)
        : id(0),
        depth(0),
        data(source.data),
        parentNode(nullptr),
        leftNode(nullptr),
        rightNode(nullptr),
        leftNodeType(THREAD),
        rightNodeType(THREAD)
    {
    }

    /**
     * Node(const string& token)
     *
     * Constructor
     *
     * @param token Input token to copy & store.
     */
    Node::Node(const std::string& token)
        : id(0),
        depth(0),
        parentNode(nullptr),
        leftNode(nullptr),
        rightNode(nullptr),
        leftNodeType(THREAD),
        rightNodeType(THREAD)
    {
        data.setToken(token);
    }

    /**
     * operator==(const Node& target) const
     *
     * Equality operator
     *
     * @param target The node used as comparison target.
     * @pre None
     * @post The local data is compared against the target data.
     * @return True if the data are matching; false otherwise.
     */
    bool Node::operator==(const Node& target) const
    {
        return
            (id == target.id) &&
            (depth == target.depth) &&
            (data == target.data.getToken()) &&
            (data.getFrequency() == target.data.getFrequency());
    }

    /**
     * operator!=(const Node& target) const
     *
     * Inequality operator
     *
     * @param target The node used as comparison target.
     * @pre None
     * @post The local data is compared against the target data.
     * @return False if the data are matching; true otherwise.
     */
    bool Node::operator!=(const Node& target) const
    {
        return
            (id != target.id) ||
            (depth != target.depth) ||
            (data != target.data.getToken()) ||
            (data.getFrequency() != target.data.getFrequency());
    }

    /**
     * show(ostream& output, bool details) const
     *
     * Helper method for pushing the node data information into an output stream.
     *
     * @param output Output stream
     * @param details Whether to display extended info
     * @pre None
     * @post data is pushed into the stream.
     */
    void Node::show( std::ostream& output, bool details) const
    {
        if (details)
        {
            output << "\tId: " << id << "\t";
            data.show(output, true);
            output << ", Depth: " << depth;
            if (parentNode != nullptr)
            {
                output << ", Parent: " << parentNode->data.getToken().c_str();
            }
            if (leftNode != nullptr)
            {
                output << ", Left: " << leftNode->data.getToken().c_str();
            }
            if (rightNode != nullptr)
            {
                output << ", Right: " << rightNode->data.getToken().c_str();
            }
            output << "\r\n";
        }
        else
        {
            data.show(output, false);
        }
    }
}
