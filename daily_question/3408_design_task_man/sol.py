from typing import List, Dict

# task int order: userId, taskId, priority
class TaskManager:
    tasks: List[List[int]]
    indexForId: Dict[int, int]

    def __init__(self, tasks: List[List[int]]):
        self.tasks = tasks
        self._sort_by_priority()
    
    def _sort_by_priority(self):
        self.tasks.sort(key=lambda x: x[2])
        self._index_all_tasks()

    def _index_all_tasks(self):
        self.indexForId = {}
        for i, task in enumerate(self.tasks):
            self.indexForId[task[1]] = i

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.indexForId[taskId] = len(self.tasks)
        self.tasks.append[[userId, taskId, priority]]
        self._sort_by_priority()

    def edit(self, taskId: int, newPriority: int) -> None:
        task = self.tasks[self.indexForId[taskId]]
        edited = [task[0], task[1], newPriority]
        self.tasks[self.indexForId[taskId]] = edited

    def rmv(self, taskId: int) -> None:
        self.tasks.pop(self.indexForId[taskId])
        self.indexForId.pop(taskId)

    def execTop(self) -> int:
        pass

    


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()