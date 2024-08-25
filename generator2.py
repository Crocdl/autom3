import random

def generate_maze(width, height):
    maze = [['#'] * width for _ in range(height)]
    start_x = random.randint(1, width - 2)
    start_y = random.randint(1, height - 2)
    maze[start_y][start_x] = ' '

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    stack = [(start_x, start_y)]

    while stack:
        x, y = stack.pop()
        random.shuffle(directions)
        for dx, dy in directions:
            nx, ny = x + dx * 2, y + dy * 2
            if 1 <= nx < width - 1 and 1 <= ny < height - 1 and maze[ny][nx] == '#':
                maze[ny][nx] = ' '
                maze[ny - dy][nx - dx] = ' '
                stack.append((nx, ny))

    exit_x = random.randint(1, width - 2)
    maze[height - 1][exit_x] = 'Ex'

    materials = ['glass', 'wood', 'iron', 'iron|wood', 'glass|iron']
    for y in range(height):
        for x in range(width):
            if maze[y][x] == '#':
                maze[y][x] = random.choice(materials)

    return maze

def save_maze_to_file(maze, filename):
    with open(filename, 'w') as file:
        for row in maze:
            formatted_row = ','.join(''.join(material) if material != ' ' else ' ' for material in row)
            file.write(formatted_row + '\n')

width, height = 5, 5
maze = generate_maze(width, height)
save_maze_to_file(maze, 'maze.txt')
