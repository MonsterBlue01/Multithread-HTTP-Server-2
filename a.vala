using GLib;

List<int> backtrack(List<int> path, List<int> vertices_left) {
    if (vertices_left.length == 0) {
        return path;
    }

    foreach (int v in vertices_left) {
        path.append(v);
        vertices_left.remove(v);
        var result = backtrack(path, vertices_left);
        if (result != null) {
            return result;
        }

        path.remove(path.length - 1);
        vertices_left.append(v);
    }

    return null;
}