
//  * Definition for a binary tree node.
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.left = (left === undefined ? null : left)
        this.right = (right === undefined ? null : right)
    }
}

function solve(root: TreeNode | null, cameraref: { camera: number }): number {
    if (root === null) {
        return 1;
    }
    let left: number = solve(root.left, cameraref);
    let right: number = solve(root.right, cameraref);
    if (left === 0 || right === 0) {
        cameraref.camera++;
        return 2;
    }
    if (left === 2 || right === 2) {
        return 1;
    }
    return 0;
}

function minCameraCover(root: TreeNode | null): number {
    let cameraref = { camera: 0 };
    if (solve(root, cameraref) === 0) return ++cameraref.camera;

    return cameraref.camera;
};
/*
968. Binary Tree Cameras
Solved
Hard
Topics
Companies
You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0

Seen this question in a real interview before?
1/5
Yes
No
Accepted
151.2K
Submissions
322.3K
Acceptance Rate
46.9%

*/