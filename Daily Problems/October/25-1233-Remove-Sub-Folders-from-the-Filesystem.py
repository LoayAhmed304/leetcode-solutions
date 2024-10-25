class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        result = []

        result.append(folder[0])
        for i in range(1, len(folder)):
            fName = result[-1] + "/"
            if not folder[i].startswith(fName):
                result.append(folder[i])
        return result
