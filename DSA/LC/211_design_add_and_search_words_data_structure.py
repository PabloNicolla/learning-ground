class TrieNode:
    def __init__(self):
        self.word = False
        self.children = {}


class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root

        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()

            curr = curr.children[c]

        curr.word = True

    def search(self, word: str) -> bool:

        def dfs(root, i):

            if i == len(word):
                return root.word
            if word[i] == '.':
                for k in root.children:
                    if dfs(root.children[k], i + 1):
                        return True

            elif word[i] in root.children:
                return dfs(root.children[word[i]], i + 1)

            return False
        return dfs(self.root, 0)
