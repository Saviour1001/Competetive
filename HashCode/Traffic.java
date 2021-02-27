import java.io.*;
import java.util.*;

public class Traffic {
    public static void main(String[] args) throws Exception {
        File file = new File("input/Traffic/c.txt");
        Input input = getInput(file);

        StringBuffer sb = new StringBuffer("");
        sb.append(input.unique.size());
        sb.append("\n");

        for (int key : input.roadsInto.keySet()) {
            Set<String> streets = input.roadsInto.get(key);
            System.out.println(key);
            sb.append(key);
            sb.append("\n");
            sb.append(streets.size());
            sb.append("\n");

            for (String street : streets) {
                sb.append(String.format("%s %d\n", street, 1));
            }
        }


        PrintWriter writer = new PrintWriter("c-output.txt", "UTF-8");
        writer.write(sb.toString());
        writer.close();

    }

    public static Input getInput(File file) throws Exception {
        boolean firstLine = true;
        Input input = new Input();
        int streets = 0;

        try(BufferedReader br = new BufferedReader(new FileReader(file))) {
            for(String line; (line = br.readLine()) != null;) {
                String[] numbers = line.split(" ");

                if (firstLine) {
                    input.setSimDuration(Integer.parseInt(numbers[0]));
                    input.setIntersections(Integer.parseInt(numbers[1]));
                    input.setStreets(Integer.parseInt(numbers[2]));
                    input.setCars(Integer.parseInt(numbers[3]));
                    firstLine = false;
                }
                else if (streets < input.getStreets()){
                    Description description = new Description(Integer.parseInt(numbers[0]), Integer.parseInt(numbers[1]), Integer.parseInt(numbers[3]), numbers[2]);
                    input.addDescription(description);
                    streets++;
                }
                else {
                    Path path = new Path(Integer.parseInt(numbers[0]));
                    List<Description> des = input.getDescriptions();
                    for (int i = 1; i < numbers.length; i++) {
                        path.addPath(numbers[i]);
                        if (i == 1) {
                            for (Description d : des) {
                                if (d.street.equals(numbers[i])) {
                                    input.unique.put(d.end, input.unique.getOrDefault(d.end, 0) + 1);
                                    if (input.roadsInto.containsKey(d.end)) {
                                        input.roadsInto.get(d.end).add(d.street);
                                    } else {
                                        Set<String> set = new HashSet<>();
                                        set.add(d.street);
                                        input.roadsInto.put(d.end, set);
                                    }
                                }
                            }
                        }
                        else if (i == numbers.length - 1) {
                            for (Description d: des) {
                                if (d.street.equals(numbers[i])) {
                                    input.unique.put(d.start, input.unique.getOrDefault(d.start, 0) + 1);

//                                    if (input.roadsInto.containsKey(d.end)) {
//                                        input.roadsInto.get(d.end).add(d.street);
//                                    } else {
//                                        Set<String> set = new HashSet<>();
//                                        set.add(d.street);
//                                        input.roadsInto.put(d.end, set);
//                                    }
                                }

                            }
                        }
                        else {
                            for (Description d: des) {
                                if (d.street.equals(numbers[i])) {
                                    input.unique.put(d.start, input.unique.getOrDefault(d.start, 0) + 1);
                                    input.unique.put(d.end, input.unique.getOrDefault(d.end, 0) + 1);

                                    if (input.roadsInto.containsKey(d.end)) {
                                        input.roadsInto.get(d.end).add(d.street);
                                    } else {
                                        Set<String> set = new HashSet<>();
                                        set.add(d.street);
                                        input.roadsInto.put(d.end, set);
                                    }
                                }
                            }
                        }
                    }
                    input.addPath(path);
                }


            }
        }

        return input;
    }

    public static void writeOutput(List<Output> outputs, File outFile) throws Exception {
        try (Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outFile)))) {
            for (Output output : outputs) {
                writer.write(output.a + "\n");
            }
        }
    }
}

class Input {
    Integer simDuration;
    Integer intersections;
    Integer streets;
    Integer cars;
    List<Description> descriptions;
    List<Path> carPaths;
    Map<Integer, Integer> unique;
    Map<Integer, Set<String>> roadsInto;

    public Input() {
        this.descriptions = new ArrayList<>();
        this.carPaths = new ArrayList<>();
        this.unique = new HashMap<>();
        this.roadsInto = new HashMap<>();
    }

    public Integer getSimDuration() {
        return simDuration;
    }

    public void setSimDuration(Integer simDuration) {
        this.simDuration = simDuration;
    }

    public Integer getIntersections() {
        return intersections;
    }

    public void setIntersections(Integer intersections) {
        this.intersections = intersections;
    }

    public Integer getStreets() {
        return streets;
    }

    public void setStreets(Integer streets) {
        this.streets = streets;
    }

    public Integer getCars() {
        return cars;
    }

    public void setCars(Integer cars) {
        this.cars = cars;
    }

    public List<Description> getDescriptions() {
        return descriptions;
    }
    public void setDescriptions(List<Description> descriptions) {
        this.descriptions = descriptions;
    }

    public List<Path> getCarPaths() {
        return carPaths;
    }

    public void setCarPaths(List<Path> carPaths) {
        this.carPaths = carPaths;
    }

    public void addDescription(Description description) {
        this.descriptions.add(description);
    }

    public void addPath(Path path) {
        this.carPaths.add(path);
    }

    @Override
    public String toString() {
        return "Input{" +
                "simDuration=" + simDuration +
                ", intersections=" + intersections +
                ", streets=" + streets +
                ", cars=" + cars +
                ", descriptions=" + descriptions +
                ", paths=" + carPaths +
                '}';
    }
}

class Description {
    Integer start;
    Integer end;
    Integer finishTime;
    String street;

    public Description(Integer start, Integer end, Integer finishTime, String street) {
        this.start = start;
        this.end = end;
        this.finishTime = finishTime;
        this.street = street;
    }


    @Override
    public java.lang.String toString() {
        return "Description{" +
                "start=" + start +
                ", end=" + end +
                ", finishTime=" + finishTime +
                ", street='" + street +
                '}';
    }
}

class Path {
    Integer numStreets;
    List<String> streetsToTravel;

    public Path(Integer numStreets) {
        this.numStreets = numStreets;
        this.streetsToTravel = new ArrayList<>();
    }

    public Integer getNumStreets() {
        return numStreets;
    }

    public void setNumStreets(Integer numStreets) {
        this.numStreets = numStreets;
    }

    public List<String> getStreetsToTravel() {
        return streetsToTravel;
    }

    public void setStreetsToTravel(List<String> streetsToTravel) {
        this.streetsToTravel = streetsToTravel;
    }

    public void addPath(String path) {
        this.streetsToTravel.add(path);
    }

    @Override
    public java.lang.String toString() {
        return "Path{" +
                "numStreets=" + numStreets +
                ", streetsToTravel=" + streetsToTravel +
                '}';
    }
}

class Output {
    Integer a;
    Integer b;

    public Integer getA() {
        return a;
    }

    public void setA(Integer a) {
        this.a = a;
    }

    public Integer getB() {
        return b;
    }

    public void setB(Integer b) {
        this.b = b;
    }

    @Override
    public String toString() {
        return "Output{" +
                "a=" + a +
                ", b=" + b +
                '}';
    }
}
