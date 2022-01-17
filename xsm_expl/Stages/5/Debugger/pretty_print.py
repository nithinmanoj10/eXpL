class ASTPrinter:

    def __init__(self,val):
        self.val = val

    def to_string(self):
        nodeType = self.val['nodeType']
        print("")
        print(f"dataType: {getDataTypeName(self.val['dataType'])}")
        print(f"nodeType: {getNodeTypeName(nodeType)}")
        print(f"nodeName: {str(self.val['nodeName'])}")
        return str("")

def my_expl_pp_func(val):
    if str(val.type) == 'struct ASTNode *':
        return ASTPrinter(val)

def getNodeTypeName(nodeType):
    
    if nodeType == 22:
        return "SLIST"

def getDataTypeName(dataType):

    if dataType == 50:
        return "int"

    if dataType == 51:
        return "bool"

    if dataType == 52:
        return "void"

    if dataType == 53:
        return "str"

    if dataType == 54:
        return "int*"

    if dataType == 55:
        return "str*"

gdb.pretty_printers.append(my_expl_pp_func)