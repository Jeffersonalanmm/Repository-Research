from collections import deque

class Queue:
    """
    A class representing a queue data structure.
    
    Attributes:
    ----------
    queue : deque
        A double-ended queue to store elements.
        
    Methods:
    -------
    enqueue(element)
        Adds an element to the end of the queue.
    dequeue()
        Removes an element from the front of the queue.
    peek()
        Returns the element at the front of the queue without removing it.
    is_empty()
        Checks if the queue is empty.
    size()
        Returns the number of elements in the queue.
    """

    def __init__(self):
        """
        Initializes an empty queue.
        """
        self.queue = deque()

    def enqueue(self, element):
        """
        Adds an element to the end of the queue.
        
        Parameters:
        ----------
        element : any
            The element to be added to the queue.
        """
        self.queue.append(element)

    def dequeue(self):
        """
        Removes an element from the front of the queue.
        
        Returns:
        -------
        any
            The removed element.
        
        Raises:
        ------
        IndexError
            If the queue is empty.
        """
        if self.is_empty():
            raise IndexError("Cannot dequeue from an empty queue")
        return self.queue.popleft()

    def peek(self):
        """
        Returns the element at the front of the queue without removing it.
        
        Returns:
        -------
        any
            The element at the front of the queue.
        
        Raises:
        ------
        IndexError
            If the queue is empty.
        """
        if self.is_empty():
            raise IndexError("Cannot peek an empty queue")
        return self.queue[0]

    def is_empty(self):
        """
        Checks if the queue is empty.
        
        Returns:
        -------
        bool
            True if the queue is empty, False otherwise.
        """
        return len(self.queue) == 0

    def size(self):
        """
        Returns the number of elements in the queue.
        
        Returns:
        -------
        int
            The number of elements in the queue.
        """
        return len(self.queue)
