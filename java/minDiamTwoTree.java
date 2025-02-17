import java.util.*;

class Solution {
    public List<List<Integer>> createGraph(int[][] edges, int length, List<List<Integer>> graph) {

        for (int i = 0; i < length; i++) {
            graph.get(edges[i][0]).add(edges[i][1]);
            graph.get(edges[i][1]).add(edges[i][0]);
        }

        return graph;
    }

    public void printGraph(List<List<Integer>> graph) {
        int length = graph.size();

        for (int i = 0; i < length; i++) {
            System.out.print(i + " -> ");
            for (int j = 0; j < graph.get(i).size(); j++) {
                System.out.print(graph.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public int[] getFarthestNodeAndDistance(List<List<Integer>> graph, int root) {
        int diameter = graph.size();
        int distance = 0;

        Queue<Integer> que = new LinkedList<>();
        boolean[] vis = new boolean[diameter];
        int farthestNode = root;

        que.add(root);
        vis[root] = true;

        while (que.size() > 0) {
            int size = que.size();

            while (size-- > 0) {
                int node = que.poll();
                farthestNode = node;

                for (int i = 0; i < graph.get(node).size(); i++) {
                    int child = graph.get(node).get(i);

                    if (vis[child] == false) {
                        vis[child] = true;
                        que.add(child);
                    }
                }
            }

            if (que.size() > 0) {
                distance++;
            }
        }

        return new int[] { farthestNode, distance };
    }

    public int getFarthestNode(List<List<Integer>> graph, int root) {
        int diameter = graph.size();

        Queue<Integer> que = new LinkedList<>();
        boolean[] vis = new boolean[diameter];
        int farthestNode = root;

        que.add(root);
        vis[root] = true;

        while (que.size() > 0) {
            int size = que.size();

            while (size-- > 0) {
                int node = que.poll();
                farthestNode = node;

                for (int i = 0; i < graph.get(node).size(); i++) {
                    int child = graph.get(node).get(i);

                    if (vis[child] == false) {
                        vis[child] = true;
                        que.add(child);
                    }
                }
            }
        }

        return farthestNode;
    }

    public int getMaxDistance(List<List<Integer>> graph, int root) {
        int diameter = graph.size();

        Queue<Integer> que = new LinkedList<>();
        boolean[] vis = new boolean[diameter];
        int distance = 0;

        que.add(root);
        vis[root] = true;

        while (que.size() > 0) {
            int size = que.size();

            while (size-- > 0) {
                int node = que.poll();

                for (int i = 0; i < graph.get(node).size(); i++) {
                    int child = graph.get(node).get(i);

                    if (vis[child] == false) {
                        vis[child] = true;
                        que.add(child);
                    }
                }
            }
            distance++;
        }

        return distance - 1;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int length1 = edges1.length;
        int length2 = edges2.length;

        List<List<Integer>> graph1 = new ArrayList<>(length1);
        List<List<Integer>> graph2 = new ArrayList<>(length2);

        for (int i = 0; i < length1 + 1; i++) {
            graph1.add(new ArrayList<>());
        }
        for (int i = 0; i < length2 + 1; i++) {
            graph2.add(new ArrayList<>());
        }

        graph1 = createGraph(edges1, length1, graph1);
        graph2 = createGraph(edges2, length2, graph2);

        printGraph(graph1);
        printGraph(graph2);

        // next step is to get the farthest node from the root node in both the treess
        // and then try getting the diameter of the tree

        // older code
        /*
         * int root1 = 0;
         * int root2 = 0;
         * 
         * root1 = getFarthestNode(graph1, root1);
         * root2 = getFarthestNode(graph2, root2);
         * 
         * int maxDistance1 = getMaxDistance(graph1, root1);
         * int maxDistance2 = getMaxDistance(graph2, root2);
         */

        // new code

        int[] ans1 = getFarthestNodeAndDistance(graph1, 0);
        ans1 = getFarthestNodeAndDistance(graph1, ans1[0]);
        int[] ans2 = getFarthestNodeAndDistance(graph2, 0);
        ans2 = getFarthestNodeAndDistance(graph2, ans2[0]);

        int maxDistance1 = ans1[1];
        int maxDistance2 = ans2[1];

        System.out.println("Max distance 1: " + maxDistance1);
        System.out.println("Max distance 2: " + maxDistance2);
        System.out
                .println("Max distance when combinaed can be" + ((maxDistance1 + 1) / 2 + (maxDistance2 + 1) / 2) + 1);

        return Math.max(Math.max(maxDistance1, maxDistance2), (maxDistance1 + 1) / 2 + (maxDistance2 + 1) / 2 + 1);
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        // edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 =
        // [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

        int[][] edges1 = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 2, 7 } };
        int[][] edges2 = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 2, 7 } };

        System.out.println(s.minimumDiameterAfterMerge(edges1, edges2));
    }
}