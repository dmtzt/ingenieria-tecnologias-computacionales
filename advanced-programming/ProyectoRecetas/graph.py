#!/usr/bin/python
import constants
import csv
import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

# Solicita nombre de archivo
file_name = 'Output.txt'

# Abre archivo y extrae valores <nodo_u> <nodo_v> <peso>
with open(file_name, newline = '') as output_file:
    edges = csv.reader(output_file, delimiter = '\t')

    for edge in edges:
        G.add_edge(edge[constants.U], edge[constants.V], weight = float(edge[constants.WEIGHT]))

for line in nx.generate_adjlist(G):
        print(line)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.savefig("img.png")