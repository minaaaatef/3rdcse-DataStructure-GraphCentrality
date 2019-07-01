from pyvis.network import Network

def Data_Visualisation  (Algor1, Algor2):

    net = Network()

    inputFile = open(r"inputFile.txt","r+")

    firstline = inputFile.readline()
    [n,m] = firstline.split()
    n = int(n)
    m = int(m)


    sizes = Algor1


    for node in range(n):
        net.add_node(node, label=node.__str__(),size=float(sizes[node].split()[0])*10)


    input_lines = inputFile.readlines()
    for line in input_lines :
        edgelist = line.split()
        net.add_edge(int(edgelist[0]), int(edgelist[1]), title = int(edgelist[2].__str__()))

    net.save_graph('Degree Centrality.html')

    net = Network()

    inputFile = open(r"inputFile.txt", "r+")

    firstline = inputFile.readline()
    [n, m] = firstline.split()
    n = int(n)
    m = int(m)

    sizes = Algor2

    for node in range(n):
        net.add_node(node, label=node.__str__(), size=float(sizes[node].split()[0]) * 40)

    input_lines = inputFile.readlines()
    for line in input_lines:
        edgelist = line.split()
        net.add_edge(int(edgelist[0]), int(edgelist[1]), title=int(edgelist[2].__str__()))

    net.save_graph('Closeness Centrality.html')



