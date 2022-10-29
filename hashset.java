class MyHashSet {

    List<Integer> list;
        public MyHashSet() {
            list = new ArrayList<>();
        }

        public void add(int key) {
            int i = Collections.binarySearch(list, key);
            if (i < 0) {
                list.add(-i - 1, key);
            }
        }

        public void remove(int key) {
            int i = Collections.binarySearch(list, key);
            if (i >= 0) list.remove(i);
        }

        public boolean contains(int key) {
            int k = Collections.binarySearch(list, key);
            if (k < 0) {
                return false;
            } else {
                return true;
            }
        }
}
