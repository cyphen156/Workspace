using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _25._04._21_DataStructure_LiveShare
{
    internal class Graph
    {
        int size;
        List<List<int>> graph = new List<List<int>>();

        public Graph(int inSize) 
        {
            size = inSize + 1;
            for (int i = 0; i < size; ++i)
            {
                List<int> list = new List<int>();
                graph.Add(list);
            }
        }

        public void Link(int vertex, int vertex2)
        {
            graph[vertex].Add(vertex2);
            graph[vertex2].Add(vertex); 
        }

        public int Length()
        {
            return graph.Count;
        }

        public List<int> GetVertex(int index)
        {
            return graph[index]; 
        }
    }

    class DFS
    {
        static bool[] visited;
        static Graph graph;

        public static int Search(Graph g, int vertex) 
        {
            graph = g;
            visited = new bool[g.Length()];
            
            return Visit(vertex) - 1;
        }

        private static int Visit(int vertex)
        {
            // 아니면 연결된 모든 링크 탐색
            visited[vertex] = true;

            int count = 1;

            List<int> newVertex = graph.GetVertex(vertex);

            foreach (var linkedVertex in newVertex)
            {
                if (visited[linkedVertex] == false)
                {
                    count += Visit(linkedVertex);
                }
            }

            return count;
        }
        
    }
    class Program
    {
        public static void Main()
        {
            int computerNum = int.Parse(Console.ReadLine());
            Graph g = new Graph(computerNum);
            int links = int.Parse(Console.ReadLine());

            for (int i = 0; i < links; ++i)
            {
                int[] inputs = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
                g.Link(inputs[0], inputs[1]);
            }
            Console.WriteLine(DFS.Search(g, 1));
        }
    }
}
