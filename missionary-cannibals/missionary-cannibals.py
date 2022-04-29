
class NodoArvore:
    def __init__(self, status={"missionaryR":"", "cannibalsR":"", "missionaryL":"", "cannibalsL":""}, chave = None, leaf = []):
        self.status = status
        self.chave = chave
        self.leaf = leaf

    def __repr__(self):
        st = ""
        for i in self.leaf:
            st += str(i) + ", "
        return '%s -> %s ' % (self.chave, st)




tree = NodoArvore({"missionaryR":"3", "cannibalsR":"3", "missionaryL":"0", "cannibalsL":"0"}, 0)

